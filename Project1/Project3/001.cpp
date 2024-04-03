 #include<iostream>
#include<cassert>
class Stack
{
private:
	int m_array[10];
	int m_next;
public:
	void reset()
	{
		m_next = 0;
		for (int i = 0; i < 10; ++i)
		{
			m_array[i] = 0;
		}
	}

	bool push(int value)
	{
		if (m_next == 10)
		{
			return false;
		}
		m_array[m_next++] = value;
		return true;
	}

	int pop()
	{
		assert(m_next > 0);
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "(";
		for (int i = 0; i < m_next; ++i)
			std::cout << m_array[i] << " " << ")\n";
	}
};


#include<iostream>
#include<cstring>
class  Ball
{
private:
	std::string m_color;
	double m_radius;
public:
	Ball()
	{
		m_color = "red";
		m_radius = 20.0;
	}
	Ball(const std::string &color)
	{
		m_color = color;
		m_radius = 20;
	}
	Ball(double radius)
	{
		m_color = "red";
		m_radius = radius;
	}
	Ball(const std::string& color, double radius)
	{
		m_color = color;
		m_radius = radius;
	}
	void print()
	{
		std::cout << "color: " << m_color << "radius: " << m_radius<<"\n";
	}
};

*/
#include<cstdint>
class RGBA
{
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;
public:
	RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 0)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)