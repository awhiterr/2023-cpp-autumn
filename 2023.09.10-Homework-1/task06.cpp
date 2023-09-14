#include<iostream>
int main(int argc, char* argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a;
    std::cin >> b;
    c = a / b;
    d = b / a;
    std::cout << ((a * c) + (b * d)) / (d + c);
    return EXIT_SUCCESS;
}