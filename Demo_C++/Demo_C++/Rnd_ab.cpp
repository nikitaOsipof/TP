#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 
using namespace std;

int main() 
{
	SetConsoleOutputCP(1251);
	int a, b;
	cout << "������� ����� ����� ������� ";
	cin >> a;
	cout << "������� ������ ����� ������� ";
	cin >> b;

	srand(time(NULL));
	int rnd = rand() % (b - a + 1) + a;

	cout << "��������� ����� �� �������: [ " << a << " ; " << b << " ] ";
	cout << "����� " << rnd << endl;
	return 0;

}