#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	std::cin >> a;
	int b = 0;
	b = a / 10;
	long long c = b + 1;
	long long d = b * c * 100 + 25;
	std::cout << d;
	return 0;
}