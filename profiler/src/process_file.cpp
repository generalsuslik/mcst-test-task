#include "process.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

#include <fcntl.h>
#include <unistd.h>

void process_file(const char* file_name)
{
	const int fd = open(file_name, O_RDONLY);
	if (fd == -1) 
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}

	data_processor_t data_processor;

	constexpr std::size_t buf_size = 0x100000;
	std::vector<std::uint32_t> buf(buf_size);
	
	std::uint32_t res_hash = 0;
	ssize_t bytes_read;
	while ((bytes_read = read(fd, buf.data(), buf.size())) > 0)
	{
		if (bytes_read < buf_size) 
		{
			buf.resize(bytes_read);
		}

		res_hash = data_processor.process_block(buf);
		buf.clear();
		buf.resize(buf_size);
	}

	close(fd);

	std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << res_hash << std::endl;
}


