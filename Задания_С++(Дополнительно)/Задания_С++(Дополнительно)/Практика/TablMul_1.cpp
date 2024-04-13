/* ���������� ������. ��������� ����������� �������� ������ ������� ���������.

���������� �������
    ��������� (����): ������� (������������) � ������� ��������

���������������� �������
    " ��� ������������, ����������� ���� ������
    � ���� �������� ��������� ��� ��� � ������� ����� ������� ������ ������,
    � ����� ��������� ����� ������ ������� � �������� ��������� �������."

�������������� ����������
    ������� ������ ������ ������������ ����� �������� �� ��������� �������� ����������� ������� ���������,
    �������� ������ ��������� ����� ������� ������.
    ���� ������ ��������� ������� ��������� ���������� ��������.
    ����� ��������� ����� ������� ������ ���������� � ����������� ����� � ���������� ��������� ��������

����� �������
    ����������� ��������� ��������� ����� ��� �������� � ���� ������
    ����������� ������ ������ ������� - ����
    ����������� �������� �������� ������������ ������
    ����������� ������� ���������� ��������� �������
    ����������� ����������� ����������� ����� ��� ���������� ������ ������ 
*/    


/* ������ ������
������ ������� ���������: ������������� ��� ����� ����� � ��������� �� 1 �� 10
������: ��� ���������� ������ ����: ��� �������� (a, b) � ��������� ��������� (�)
����������� �������� ������������ ����� � ����� ���������������� ���������
*/
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std:: endl;

int main()
{
	srand(time(NULL));
	int c = 0;

   // ������������� ��������� ���������� ������� �� 1 �� 10 (r = min + rand() % (max � min +1))
   int a = rand() % 10 + 1;
   int b = rand() % 10 + 1;

   

   cout << a << " * " << b << " = ";	// ����� �������
   cin >> c;							// ���� ������
   
   int ans = a * b;						// ������ ����������� ����������
   if (ans == c)
   {   // ����� ����������� ����������
	   cout << "OK: " << a << " * " << b << " = " << ans << endl;
   }
   else
   {
	   cout << "Error!\n"; 
   }

    return 0;
}