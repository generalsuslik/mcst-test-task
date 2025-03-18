#include "process.hpp"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#include <fcntl.h>
#include <unistd.h>

/**
 * @brief reads file by blocks of size 0x100000 and computes file has
 *
 * @param file_name - path to file
 *
 * @return - hash of this file
 */
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
		// do not process bytes, that cannot form std::uin32_t
		if (bytes_read < sizeof(std::uint32_t)) 
		{
			break;
		}

		// if we read less then buffer size
		if (bytes_read < buf_size) 
		{
			buf.resize(bytes_read);
		}

		// compute hash and clear the buffer for new block
		res_hash = data_processor.process_block(buf);
		if (buf.size() < buf_size)
		{
			buf.resize(buf_size);
		}
		
		std::ranges::fill(buf, 0);
	}

	close(fd);

	return res_hash;
}


