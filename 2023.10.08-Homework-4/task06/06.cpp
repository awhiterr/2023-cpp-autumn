#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;

	int* m = (int*)malloc(sizeof(int) * n);
	std::cin >> *(m);

	int max = *(m);
	int max_index = 0;
	int min = *(m);
	int min_index = 0;

	for (int i = 1; i < n; i++)
	{
		std::cin >> *(m + i);

		if (*(m + i) >= max)
		{
			max = *(m + i);
			max_index = i;
		}

		if (*(m + i) < max)
		{
			min = *(m + i);
			min_index = i;
		}
	}

	*(m + max_index) = min;
	*(m + min_index) = max;

	for (int i = 0; i < n; i++)
	{
		std::cout << *(m + i) << " ";
	}

	free(m);
	return EXIT_SUCCESS;
}
