#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 
using namespace std;

int func (int, int);




int main() 
{
    SetConsoleOutputCP(1251);
    int a, b;
    cout << "������� ����� ����� ������� ";
    cin >> a;
    cout << "������� ������ ����� ������� ";
    cin >> b;

    cout << func (a, b) << endl;
	cout << "������� [ " << a << " ; " << b << " ]" << endl; 
    
    return 0;

}

int func (int x, int y) {
     srand(time(NULL));
     int rnd = rand()%(y-x+1)+x;
     return rnd;
}