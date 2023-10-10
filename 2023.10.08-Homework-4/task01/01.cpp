#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	int k = 0;
	std::cin >> n;

	int* m = (int*)malloc(sizeof(int) * n);

	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(m + i);

		if (*(m + i) > 0)
		{
			sum++;
		}

	}
	std::cout << sum << " ";

	free(m);
	return EXIT_SUCCESS;
}

