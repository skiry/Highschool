#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

int main(int argc, char* argv[])
{
    std::clock_t start;
    double duration;

    std::cout << "Starting std::cout test." << std::endl;
    start = std::clock();

    for (int i = 0; i < 1000; i++)
    {
        std::cout << "Hello, World! (" << i << ")" << std::endl;
    }

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    std::cout << "Ending std::cout test." << std::endl;
    std::cout << "Time taken: " << duration << std::endl;

    std::system("pause");

    std::cout << "Starting std::printf test." << std::endl;
    start = std::clock();

    for (int i = 0; i < 1000; i++)
    {
        std::printf("Hello, World! (%i)\n", i);
        std::fflush(stdout);
    }

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    std::cout << "Ending std::printf test." << std::endl;
    std::cout << "Time taken: " << duration << std::endl;

    system("pause");

    return 0;
}
