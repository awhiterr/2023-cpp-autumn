#pragma once
#include <iostream>

void printMenu();
void printArray(int*& n, int& len);
void expandArray(int*& n, int& len);
void addElement(int*& n, int& len, int element);
void contractArray(int*& n, int& len);
void removeElement(int*& n, int& len, int index);
void deleteDuplicates(int*& n, int& len, int& index);
void swapElements(int*& n, int& len, int& min, int& max, int& temp);
void reverseArray(int* n, int len);
void sortArray(int*& n, int& len);
void addRandomElement(int*& n, int& len, int number);