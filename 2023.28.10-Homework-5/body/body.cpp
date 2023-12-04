#include <iostream>
#include "header.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
	int* n = nullptr;
	int len = 0;
	bool exit = false;

	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(n, len);

		}

		int choice = 0;
		{
			std::cin >> choice;
		}


		switch (choice)
		{

		case 0:
		{
			exit = true;
			break;
		}
		case 1:
		{
			printArray(n, len);
			system("pause");
			break;
		}

		case 2:
		{
			int element = 0;
			std::cout << "input element to add: " << std::endl;
			std::cin >> element;
			addElement(n, len, element);
			break;
		}

		case 3:
		{
			int index = 0;
			std::cout << "input index to remove" << std::endl;
			std::cin >> index;
			std::cout << "removed " << removeElement(n, len, index) << std::endl;
			break;
		}
		case 4:
		{
			sortArray(n, len);
			break;
		}
		case 5:
		{
			reverseArray(n, len);
			break;
		}
		case 6:
		{
			swapElements(n, len);
			break;
		}
		case 7:
		{
			deleteDuplicates(n, len);
			break;
		}

		case 8:
		{
			int number = 0;
			std::cout << "input number of elements to add" << std::endl;
			std::cin >> number;
			addRandomElement(n, len, number);
			break;
		}

		default:
		{
			std::cout << "unknown command" << std::endl;
			break;
		}
	}
		delete[] n;
		return EXIT_SUCCESS;
}