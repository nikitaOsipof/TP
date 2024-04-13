#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x, y, z;
	char op;
	
	cout << "¬ведите первый операнд:  ";
	cin >> x;
	cout << "¬ведите операцию:  ";
	cin >> op;
	cout << "¬ведите второй операнд:  ";
	cin >> y;
		switch (op)
		{
		case '+':
				z = x+y;
				break;
		case '-':
				z = x-y;
				break;
		case '*':
				z = x*y;
				break;
		case '/':
		case ':':
				z = x/y;
				break;
		}
	cout << "z = " << z << endl;
return 0;
}
