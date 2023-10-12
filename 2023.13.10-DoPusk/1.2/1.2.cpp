#include <iostream>

int main(int argc, char* argv[])
{
	unsigned int n = 0;
	std::cin >> n;

	const int BITS = sizeof(unsigned int) * 8;

	if (n == 0)
	{
		n = ~n;
	}
	else
	{
		int start = BITS - 1;
		int end = 0;

		while ((n >> start & 1) == 0)
		{
			start--;
		}

		while ((n >> end & 1) == 0)
		{
			++end;
		}

		start--;
		end++;

		unsigned int mask = 0;
		for (int i = end; i <= start; ++i)
		{
			mask = mask | (1 << i);
		}

		n = n ^ mask;

		std::cout << "0b ";
		for (int i = BITS - 1; i >= 0; --i)
		{
			std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}