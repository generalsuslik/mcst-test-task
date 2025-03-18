#include "process_file.hpp"

#include <iomanip>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		std::cerr << "Invalid programm arguments. "
					<< "It should be: " << argv[0] << " <file_name>" << std::endl;
		exit(EXIT_FAILURE);
	}

	// just cout formatted file hash
	std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << process_file(argv[1]) << std::endl;
	
	return 0;
}

