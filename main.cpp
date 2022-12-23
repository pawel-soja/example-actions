#include <iostream>
#include <zlib.h>

int main(int, char *[])
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "zlib version: " << zlibVersion() << std::endl;

#ifdef HAVE_TIMESPEC_GET
    std::cout << "HAVE_TIMESPEC_GET: yes" << std::endl;
#else
    std::cout << "HAVE_TIMESPEC_GET: no" << std::endl;
#endif

#ifdef HAVE_CLOCK_GETTIME
    std::cout << "HAVE_CLOCK_GETTIME: yes" << std::endl;
#else
    std::cout << "HAVE_CLOCK_GETTIME: no" << std::endl;
#endif


#ifdef HAVE_TIMESPEC_GET_SYMBOL
    std::cout << "HAVE_TIMESPEC_GET_SYMBOL: yes" << std::endl;
#else
    std::cout << "HAVE_TIMESPEC_GET_SYMBOL: no" << std::endl;
#endif

#ifdef HAVE_CLOCK_GETTIME_SYMBOL
    std::cout << "HAVE_CLOCK_GETTIME_SYMBOL: yes" << std::endl;
#else
    std::cout << "HAVE_CLOCK_GETTIME_SYMBOL: no" << std::endl;
#endif

    printf("timespec_get: %p\n", timespec_get);

    return 0;
}
