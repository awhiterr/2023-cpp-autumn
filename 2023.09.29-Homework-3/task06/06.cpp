#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int first = 0;
	int second = 1;
	int next = 0;

	switch (n)
	{
	case 0:
	{
		std::cout << first;
		break;
	}
	case 1:
	{
		std::cout << second;
		break;
	}
	default:
	{
		for (int i = 1; i < n; i++)
		{
			next = second;
			second = first + second;
			first = next;
		}
		std::cout << second;
		break;
	}
	}

	return EXIT_SUCCESS;
}