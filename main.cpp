#include <iostream>
#include <zlib.h>

int main(int, char *[])
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "zlib version: " << zlibVersion() << std::endl;
    return 0;
}
