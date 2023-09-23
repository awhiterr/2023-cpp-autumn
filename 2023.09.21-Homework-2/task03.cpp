#include<iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int x = 0;

	std::cin >> a >> b >> c >> d;
	x = -b / a;

	if (a == 0 && b == 0)
	{
		std::cout << "INF";
		return 0;
	}
	else if ((a == 0) || (c * x + d == 0) || (b % a != 0))
	{
		std::cout << "NO";
	}
	else
	{
		std::cout << x;
	}
	return EXIT_SUCCESS;
}