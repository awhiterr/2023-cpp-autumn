#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	int i = 0;
	std::cin >> n;

	int* m = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(m + i);
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << *(((m + n) - 1) - i);
	}

	free(m);
	return EXIT_SUCCESS;
}
