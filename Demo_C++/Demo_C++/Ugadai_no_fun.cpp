#include <iostream>
//#include <windows.h>
#include <math.h>
#include <ctime> 


using namespace std;
	
int main() 
{ 
  // SetConsoleOutputCP(1251);
   
   srand(time(0));
   int a, i;
   int b;
   a=rand()%10;
   i=0;
  do
   {
   
   cout<<"������� ����� �� 1 �� 100:\n";
	   cin>>b;
	   i=i+1;
       if (b<a)
            cout<<"������!\n";
	   else if (b>0)
		   cout<<"������!\n";
	   else 
		   cout<<"�������!\n";
   }
   while (b!=a);
   cout<<"�����!\n";

   switch (i)
   {
   case 1:
   case 2:
	   cout<<"�� ������!\n";
	   break;
   
   case 3:
   case 4:

	   cout<<"�� ������� �����!\n";
	   break;
   case 5:
       cout<<"�� �������� �����!\n";
	   break;
   default:
	   cout<<"� ��������� ��� ���� ������� �������������!\n";
   }
} 