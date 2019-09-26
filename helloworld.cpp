// my first program in C++
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char** argv)
{
    std::cout	<< "Hello World!" << std::endl;
/*	std::cout	<< "Version "
			<< helloworld_VERSIONMAJOR << "."
			<< helloworld_VERSION_MINOR << std::endl;
 */
    
    class rate_color{
        char col;
        int rate;
    };
    enum color_type {yellow,green,red,blue,black} rainbow;
    rainbow=red;
    int cloud=3*rainbow;
    cout << cloud << endl << rainbow << endl;
    
    
	return 0;
}
