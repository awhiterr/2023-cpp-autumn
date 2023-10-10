#include<iostream>
#include<cstdlib>

int main(int argc, char** )
{
	int n = 0;
	std::cin >> n;

	int* m = (int*)malloc(sizeof(int) * n);

	int b = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(m + i);

		if (*(m + i) > 0)
		{
			b++;
		}
		else
		{
			*(m + i) = 0;

		}
	}

	int* m2 = (int*)malloc(sizeof(int) * b);

	int j = 0;

	for (int i = 0; i < n; ++i)
	{
		if (*(m + i) > 0)
		{
			*(m2 + j) = *(m + i);
			std::cout << *(m2 + j);
		}
	}
	free(m);
	free(m2);

	return EXIT_SUCCESS;

}