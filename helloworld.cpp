// my first program in C++
#include <iostream>
#include "helloworld.h"

int main(int argc, const char** argv)
{
	std::cout	<< "Hello World!" << std::endl;
	std::cout	<< "Version "
			<< helloworld_VERSIONMAJOR << "."
			<< helloworld_VERSION_MINOR << std::endl;
	return 0;
}
