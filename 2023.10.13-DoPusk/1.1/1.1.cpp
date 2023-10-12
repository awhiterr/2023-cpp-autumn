#include <iostream>

int main(int argc, char* argv[])
{
	const int BITS = sizeof(unsigned int) * 8;
	unsigned int n = 0;
	std::cin >> n;

	int sum = 0;
	for (int i = 0; i < BITS; ++i)
	{
		sum += (n >> 1) & 1;
		n = n >> 1;
	}
	std::cout << sum << std::endl;
	return EXIT_SUCCESS;
}
