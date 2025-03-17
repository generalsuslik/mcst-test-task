#include "process.hpp"

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

std::uint32_t process_file(const char* file_name)
{
	FILE* fptr = fopen(file_name, "r+b");
	if (fptr == nullptr) 
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}

	data_processor_t data_processor;

	constexpr std::size_t buf_size = 0x100000;
	std::vector<std::uint32_t> buf(buf_size);
	
	std::uint32_t res_hash = 0;
	std::size_t bytes_read;
	while ((bytes_read = fread(buf.data(), 1, buf.size(), fptr)) > 0)
	{
		res_hash = data_processor.process_block(buf);
		buf.clear();
		buf.resize(buf_size);
	}

	fclose(fptr);

	return res_hash;
}

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		std::cerr << "Invalid programm arguments. "
					<< "It should be: " << argv[0] << " <file_name>" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << process_file(argv[1]) << std::endl;

	return 0;
}

