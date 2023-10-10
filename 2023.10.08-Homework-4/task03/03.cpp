#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;

	int* m = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(m + i);

		if (*(m + i) % 2 == 1)
		{
			std::cout << *(m + i) << " ";
		}
	}
	free(m);
	return EXIT_SUCCESS;
}
