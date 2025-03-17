#include "process.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

#include <fcntl.h>
#include <unistd.h>

std::uint32_t process_file(const char* file_name)
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
		res_hash = data_processor.process_block(buf);
		buf.clear();
		buf.resize(buf_size);
	}

	close(fd);

	return res_hash;
}


