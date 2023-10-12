#include <iostream>
int main() {
	const int maxA = 0;
	const int maxB = 0;
	const int res = 0;
	int a = 0;
	int b = 0;
	do
	{
		if (a == 0)
		{
			std::cout << ">A" << std::endl;
			a = maxA;
		}
		else if (b == maxB)
		{
			std::cout << "B>" << std::endl;
			b = 0;
		}
		else
		{
			std::cout << "A>B" << std::endl;
			if (b + a <= maxB)
			{
				b += a;
				a = 0;
			}
			else
			{
				a -= maxB - b;
				b = maxB;
			}
		}
	} while (!(a == 0 && b == 0) && !((b == res) || (a == res)));
	std::cout << std::endl;
	return EXIT_SUCCESS;
}