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
   cout << "������� ����� �� 1 �� 100:\n";


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
			cout << "������!\n";
		else if (b>a)
			cout << "������!\n";
		else
			cout << "�������!\n";
		i = i + 1;
	} while (b != a);
	cout << "�����!\n";
	return i;
}

string GetStatus(int i)
{
	string rez;
	switch (i)
	{
	case 1:
	case 2:
		rez = "�� ������!";
		break;

	case 3:
	case 4:
		rez = "�� ������� �����!";
		break;

	case 5:
		rez= "�� �������� �����!";
		break;

	default:
		rez = "� ��������� ��� ���� ������� �������������!";
	}

	return rez;
}



string Sean(int a, int b)
{
	string rez;
		if (b<a)
			rez = "������!";
		else if (b>a)
			rez = "������!";
		else
			rez = "�������!";
		
	return rez;
}



