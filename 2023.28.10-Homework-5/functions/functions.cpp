#include <iostream>
#include <cstdlib>
#include <ctime>

void printMenu()
{
	std::cout << "0 - exit" << std::endl;
	std::cout << "1 - print array" << std::endl;
	std::cout << "2 - add element to array" << std::endl;
	std::cout << "3 - remove element from array" << std::endl;
	std::cout << "4 - sort array in ascending order" << std::endl;
	std::cout << "5 - expand array" << std::endl;
	std::cout << "6 - switch max and min" << std::endl;
	std::cout << "7 - delete dublicates" << std::endl;
	std::cout << "8 - add random elements" << std::endl;
}

void printArray(int*& n, int& len)
{
	if (n == nullptr)
	{
		std::cout << "empty";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << n[i] << " ";
		}
		std::cout << std::endl;
	}
}

void expandArray(int*& n, int& len)
{
	int* newArray = new int[len + 1] { 0 };

	if (n != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newArray[i] = n[i];
		}
		delete[] n;
	}
		n = newArray;
		++len;

}

void addElement(int*& n, int& len, int element)
{
	{
		expandArray(n, len);
		n[len - 1] = element;
	}
}

void contractArray(int*& n, int& len)
{
	if (n != nullptr)
	{
		int* newArray = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			newArray[i] = n[i];
		}
		delete[] n;
		n = newArray;
		--len;
	}
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

int removeElement(int*& n, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = n[index];
		for (int i = index; i < len - 1; ++i)
		{
			n[i] = n[i + 1];
		}
		contractArray(n, len);
	}
	return res;
}

void deleteDuplicates(int*& n, int& len, int& index)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int a = i + 1; a < len; ++a)
		{
			if (n[i] == n[a])
			{
				index = a;
				removeElement(n, len, index);
			}
		}
	}
}

void findMaxandMin(int* n, int len, int& max, int& min)
{
	for (int i = 1; i < len; ++i)
	{
		if (n[max] < n[i])
		{
			max = i;
		}
		if (n[min] >= n[i])
		{
			min = i;
		}
	}
}

void swapElements(int* n, int len, int& min, int& max, int& temp)
{
	temp = n[max];
	n[max] = n[min];
	n[min] = temp;
}

void reverseArray(int* n, int len)
{
	if (n == nullptr)
	{
		std::cout << "empty";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << n[len - i - 1] << " ";
		}
	}
	std::cout << std::endl;
}

void sortArray(int*& n, int& len)
{
	if (n == nullptr)
	{
		std::cout << "empty";
	}

	else
	{
		for (int s = 0; s < len - 1; ++s)
		{
			for (int i = 0; i < len - 1; ++i)
			{
				if (n[i] > n[i + 1])
				{
					std::swap(n[i], n[i + 1]);
				}
			}
		}
	}
}

void addRandomElement (int*& n, int& len, int number)
{
	srand(time(0));

	for (int i = 0; i < number; ++i)
	{
		addElement(n, len, rand());
	}
}