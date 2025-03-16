#include "process_file.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		std::cerr << "Invalid programm arguments. "
					<< "It should be: ./<app_name> <file_name>" << std::endl;
		exit(EXIT_FAILURE);
	}

	const char* file_name = argv[1];
	process_file(file_name);

	return 0;
}

