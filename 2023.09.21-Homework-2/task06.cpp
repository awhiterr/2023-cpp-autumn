#include<iostream>
int main(int argc, char* argv[]) {
	int k = 0;
	int m = 0;
	int n = 0;
	int t = 0;
	std::cin >> k >> m >> n;
	t = 2 * n / k * m;
	if (n < k)
	{
		t = m * 2;
	}
	else if (2 * n % k > 0)
	{
			t = t + m;
	}
	std::cout << t;
	return EXIT_SUCCESS;
}