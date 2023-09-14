#include <iostream>
int main(int argc, char* argv[]) {
    int d = 0;
    int N = 0;
    int s = 0;
    int n = 0;
    std::cin >> N;
    d = (abs(N - 1)) / (N - 1);
    n = ((N - 1) / d) + 1;
    s = (1 + N) * n / 2;
    std::cout << s;
    return EXIT_SUCCESS;
}
