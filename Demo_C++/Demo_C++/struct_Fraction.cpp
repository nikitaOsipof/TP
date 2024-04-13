#include <iostream>
using namespace std;

struct Fraction
{
	int m_numerator;
	int m_denominator;

	Fraction()						// конструктор по умолчанию
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	Fraction(int num, int denom)	//  конструктор с параметрами
	{
		m_numerator = num;
		m_denominator = denom;
	}

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}

};

int main()
{
	Fraction f1;			// вызывается конструктор по умолчанию
	f1.m_numerator = 3;
	f1.print();
	Fraction f2(1, 2);		// вызывается конструктор с параметрами
	f2.print();
	return 0;

}


