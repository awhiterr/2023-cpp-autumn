#include <iostream>
int main(int argc, char* argv[])
{
	int k = 0;
	int c = 0;
	std::cin >> k;
	int i = 1;

	for (i; i <= k; i++)
	{
		int a = 0;
		int j = i;
		while (j > 0)
		{
			a = j % 10 + a * 10;
			j = j / 10;
		}
		if (a == i)
		{
			c = c + 1;
		}
	}

	std::cout << c;
	return EXIT_SUCCESS;
}


