#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	std::cin >> a;
	while (a % 10 == 0)
	{
		a = a / 10;
	}
	while (a > 0)
	{
		std::cout << a % 10;
		a = a / 10;
	}
	return EXIT_SUCCESS;
}



