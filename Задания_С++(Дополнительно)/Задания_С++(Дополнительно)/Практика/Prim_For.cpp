#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std; 


int main()
{

	srand(time(NULL));
	int a, b, c;
	int k = 0, n = 100;

  for(int i=1; i<=n ;i++)
   {
	   a = rand() % 10 + 1;
	   b = rand() % 10 + 1;

	   cout << a << " * " << b << " = ";
	   cin >> c;

	   if (a == 10 || b == 10)
	   {
		   cout << "Easy! Repeat\n";
		   continue;
	   }
	   if (a*b != c)
	   {
		   k++;
           if (k>2)
           {
               cout << "Stop test! ";
               break;
           }
		   cout << "Error! ";
		   cout << a << " * " << b << " = " << a*b << endl;
	   }
   }
  
  cout << "Count error: " << k << endl;
  return 0;

}