#include <iostream>

int main(int argc, char* argv[])
{
    unsigned short int a = 0;
    std::cin >> a;
    unsigned short int b = 0;
    std::cin >> b;

    unsigned int c = a & b;
    unsigned int result = a ^ b;
    const int BITS = sizeof(unsigned int) * 8;

    while (c != 0)
    {
        unsigned int s = c << 1;
        c = result & s;
        result = result ^ s;
    }

    for (int i = BITS - 1; i >= 0; --i)
    {
        std::cout << ((result >> i) & 1) << (i % 4 == 0 ? " " : "");
    }
    std::cout << std::endl;

    std::cout << result;

    return EXIT_SUCCESS;
}