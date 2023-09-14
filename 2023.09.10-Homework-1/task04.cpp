#include<iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	std::cin >> a;
	int b = a * 100;
	int c = b + 90;
	int d = 9 - a;
	int e = c + d;
	std::cout << e;
	return 0;
}