#include <iostream>
using namespace std;

struct Fraction
{
	int m_numerator;
	int m_denominator;

	Fraction()						// ����������� �� ���������
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	Fraction(int num, int denom)	//  ����������� � �����������
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
	Fraction f1;			// ���������� ����������� �� ���������
	f1.m_numerator = 3;
	f1.print();
	Fraction f2(1, 2);		// ���������� ����������� � �����������
	f2.print();
	return 0;

}


