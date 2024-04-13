#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std; 


int main()
{

	srand(time(NULL));
	int a, b, c;
	int k = 0;

	const int n = 10;
	int mas[n];

	vector<int> v1;
	vector<int> v2;

  for(int i=0; i<n ;i++)
   {
	   a = rand() % 10 + 1;
	   b = rand() % 10 + 1;

	   cout << a << " * " << b << " = ";
	   cin >> c;

	   mas[i] = c;

	   if (a == 10 || b == 10)
	   {
		   cout << "Easy! Repeat\n";
		   continue;
	   }

	   if (a*b != c)
	   {
		   v2.push_back(c);
		   k++;
           if (k>2)
           {
               cout << "Stop test! ";
               break;
           }
		   cout << "Error! ";
		   cout << a << " * " << b << " = " << a*b << endl;
	   }
	   else
	   {
		   v1.push_back(c);
	   }
   }
  
  	cout << "\nAll: ";
  	for (int i=0; i<n; i++)
	{
		cout << mas[i] << ends; 
	}

	cout << "\nGood: ";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << ends;
	}
	
	cout << "\nBad: ";
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << ends;
	}

	cout << "\nCount error: " << k << endl;
  return 0;

}