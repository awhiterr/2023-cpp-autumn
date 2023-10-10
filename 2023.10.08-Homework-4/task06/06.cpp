#include <iostream>
#include<cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;

	int* m = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> *(m + i);
	}

	int min = 0;
	int max = 0;

	for (int i = 0; i < n; ++i)
	{
		if (*(n + i) >= *(n + max))
		{
			max = i;
		}
		if (*(n + i) < *(n + min))
		{
			min = i;
		}
	}
	int t = 0;
	t = *(a + min);
	*(a + min) = *(a + max);
	*(a + max) = t;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(n + i) << " ";
	}
	free(a);

	return EXIT_SUCCESS;
}
