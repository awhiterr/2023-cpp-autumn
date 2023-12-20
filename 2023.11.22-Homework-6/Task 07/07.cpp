#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	d[to][n[to]++] = d[from][--n[from]];
}

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoy(count - 1, from, res);
	shift(from, to);
	hanoy(count - 1, res, to);
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

int top(int a)
{
	if (n[a] > 0)
	{
		return d[a][n[a] - 1];
	} 
	else
	{
		return 1;
	}
}

void sort()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int tower = 1;


	while (n[a] > 0)
	{
		int k = top(a);
		while (top(c) < k)
		{
			int f = 0; //press f to pay respect
			for (int i = 0; i < n[b]; ++i)
			{
				if (d[b][i] > top(c))
				{
					f++;
				}
			}
			hanoy(n[b] - f, b, c);
			swap(b, c);
		}
		shift(a, c);
	}

	while (n[c] > 0)
	{
		int f = 0;
		for (int j = 0; j < n[b]; ++j)
		{
			if (d[b][j] > top(c))
			{
				f++;
			}
		}
		hanoy(n[b] - f, b, c);
		swap(b, c);
	}
}


int main(int argc, char* argv[])
{
	std::cin >> n[0];
	for (int i = 0; i < n[0]; ++i)
	{
		std::cin >> d[0][i];
	}
	sort();
	return EXIT_SUCCESS;
}