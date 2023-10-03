#include <iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int n = 1;
	int c = 0;

	for (int i = 0; i < a; i++)
	{
		std::cout << n << " ";
		c++;
		if (n == c)
		{
			n++;
			c = 0;
		}
	}
	return EXIT_SUCCESS;
}