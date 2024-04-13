#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	char op;
	
	cout << "Сделайте свой выбор, собери авто свой мечты:  ";
	cin >> op;

	switch (op)
		{
		case 'V':
			cout << "Кондиционер хочу\n";
			cout << "Радио играть должно\n";
			cout << "Колеса круглые\n";
			cout << "Мощный двигатель\n";
			break;
		case 'S':
			cout << "Радио играть должно\n";
			cout << "Колеса круглые\n";
			cout << "Мощный двигатель\n";
			break;
		default:
			cout << "Колеса круглые\n";
			cout << "Мощный двигатель\n";
		}

	switch (op)
		{
		case 'V':
			cout << "Кондиционер хочу\n";
		case 'S':
			cout << "Радио играть должно\n";
		default:
			cout << "Колеса круглые\n";
			cout << "Мощный двигатель\n";
		}
}


