#include <iostream>
//#include <windows.h>
#include <math.h>
#include <ctime> 
#include <string>

using namespace std;
	
int Rnd();
int Sean(int);
string Sean(int a, int b);
string GetStatus(int i);


int main() 
{ 
 //  SetConsoleOutputCP(1251);
   cout << "Введите число от 1 до 100:\n";


	int a = Rnd();
	cout << a << "\n";
	//int i = Sean(a);
	int b;


	int i = 0;

	do
	{	
		cin >> b;
		string rez = Sean(a, b);
		cout << rez << "\n";
		i++;
	} while (b!=a);


	string status = GetStatus(i);

	cout << status << endl;
} 


int Rnd()
{
	srand(time(0));
	int a = rand() % 100;
	return a;
}

int Sean(int a)
{
	int b;
	int i = 0;
	do
	{
		cout << a << "\n";
		cin >> b;
		if (b<a)
			cout << "Меньше!\n";
		else if (b>a)
			cout << "Больше!\n";
		else
			cout << "Угадали!\n";
		i = i + 1;
	} while (b != a);
	cout << "Верно!\n";
	return i;
}

string GetStatus(int i)
{
	string rez;
	switch (i)
	{
	case 1:
	case 2:
		rez = "Вы мастер!";
		break;

	case 3:
	case 4:
		rez = "Вы хороший игрок!";
		break;

	case 5:
		rez= "Вы неплохой игрок!";
		break;

	default:
		rez = "К сожалению Вам надо блольше тренироваться!";
	}

	return rez;
}



string Sean(int a, int b)
{
	string rez;
		if (b<a)
			rez = "Меньше!";
		else if (b>a)
			rez = "Больше!";
		else
			rez = "Угадали!";
		
	return rez;
}



