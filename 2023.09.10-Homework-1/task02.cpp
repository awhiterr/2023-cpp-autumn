#include <iostream>
int main(int argc, char* argv[]) {
	int d = 0;
	int c = 0;
	int s = 0;
	int n = 0;
	std::cin >> c;
	d = (abs(c - 1)) / (c - 1);
	n = ((c - 1) / d) + 1;
	s = (1 + c) * n / 2;
	std::cout << s;
	return EXIT_SUCCESS;
}
