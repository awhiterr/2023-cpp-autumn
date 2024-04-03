/*#include<iostream>
class DateClass
{
public:
	int m_day;
	int m_month;
	int m_year;

	void print()
	{
		std::cout << m_day << "/"<<m_month << "/" << m_year;
	}
};
int main(int argc[], char* argv)
{
	DateClass today{ 18, 03, 2023 };
	today.m_day = 31;
	today.print();
	return 0;
}*/
#include<iostream>
class Numbers
{
public:
	int m_first;
	int m_second;

	void set(int first, int second)
	{
		m_first = first;
		m_second = second;
	}
	void print()

	{
		std::cout << "Numbers(" << m_first << "," << m_second << ")\n";
	}
};

int main(int argc[], char* argv)
{
	Numbers n1;
	n1.set(3, 3);

	Numbers n2{ 4,4 };
	n1.print();
	n2.print();

	return 0;
}