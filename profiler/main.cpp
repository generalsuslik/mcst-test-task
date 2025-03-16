#include "process_file.hpp"

#include <iomanip>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		std::cerr << "Invalid programm arguments. "
					<< "It should be: ./<app_name> <file_name>" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::uint32_t res_hash = process_file(argv[1]);

	std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << res_hash << std::endl;
	
	return 0;
}

