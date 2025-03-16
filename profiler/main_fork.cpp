#include "process_file.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		std::cerr << "Invalid programm arguments. "
					<< "It should be " << argv[0] << " <file_1> <file_2> ..." << std::endl;
		exit(EXIT_FAILURE);
	}

	int nfiles = argc - 1;
	std::uint32_t* hash = static_cast<std::uint32_t*>(mmap(nullptr, nfiles * sizeof(std::uint32_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0));
	if (hash == MAP_FAILED)
	{
		perror("mmap initialization error");
		exit(EXIT_FAILURE);
	}

	std::vector<pid_t> pids;

	for (int i = 1; i < argc; ++i) 
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) 
		{
			hash[i - 1] = process_file(argv[i]);
			munmap(hash, nfiles * sizeof(std::uint32_t));
			_exit(0);
		}
		
		pids.push_back(pid);
	}

	for (const auto pid : pids) 
	{
		int status;
		waitpid(pid, &status, 0);
	}

	std::uint32_t res_hash = 0;
	for (int i = 0; i < nfiles; ++i)
	{
		res_hash ^= hash[i];
	}

	std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << res_hash << std::endl;

	return 0;
}

