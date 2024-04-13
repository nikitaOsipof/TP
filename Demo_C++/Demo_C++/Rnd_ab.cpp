#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 
using namespace std;

int main() 
{
	SetConsoleOutputCP(1251);
	int a, b;
	cout << "¬ведите левый конец отрезка ";
	cin >> a;
	cout << "¬ведите правый конец отрезка ";
	cin >> b;

	srand(time(NULL));
	int rnd = rand() % (b - a + 1) + a;

	cout << "—лучайное число на отрезке: [ " << a << " ; " << b << " ] ";
	cout << "равно " << rnd << endl;
	return 0;

}