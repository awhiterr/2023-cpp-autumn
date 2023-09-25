#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int t1 = 15; // ticket price
	int t5 = 70;
	int t10 = 125;
	int t20 = 230;
	int t60 = 440;
	std::cin >> a;

	int n1 = 0; // number of trips
	int n5 = 0;
	int n10 = 0;
	int n20 =0;
	int n60 = 0;

	n60 = a / 60; 
	int a1 = a % 60;
	n20 = a1 / 20;
	int a2 = a1 % 20;
	n10 = a2 / 10;
	int a3 = a2 % 10;
	n5 = a3 / 5;
	n1 = a3 % 5;

	if (n1 * t1 >= t5)
	{
		n1 = 0;
		n5++;
	}
	if (n1 * t1 + n5 * t5 >= t10)
	{
		n1 = 0;
		n5 = 0;
		n10++;
	}
	if (n1 * t1 + n5 * t5 + n10 * t10 >= t20)
	{
		n1 = 0;
		n5 = 0;
		n10 = 0;
		n20++;
	}
	if (n1 * t1 + n5 * t5 + n10 * t10 + n20 * t20 >= t60) {
		n1 = 0;
		n5 = 0;
		n10 = 0;
		n20 = 0;
		n60++;
	}
	std::cout << n1 << " " << n5 << " " << n10 << " " << n20 << " " << n60;
	return EXIT_SUCCESS;
}