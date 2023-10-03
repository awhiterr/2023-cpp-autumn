#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	long x = 0;
	int i = 1;
	std::cin >> x;
	for (i; x > i * i; i++)
	{
		if (x % i == 0)

		{
			a = a + 2;
		}
	}
	if (i * i == x)
	{
		a = a + 1;
	}
	std::cout << a;
	return EXIT_SUCCESS;
}