#include <iostream>
using namespace std; 



void MyFor()
{
  int i;
  float x,s,a;
x = 1;
  s=0;
  a=1;
  for(i=1;i<=7;i++)
   {
    a = a*x;
    s = s + a/i;
   }
  cout << "по циклу For s=" << s << endl;
  
}

void MyWhile()
{
	int i;
  float x,s,a;
x=1;
  s=0;
  a=1;
  i=1;
  while (i<=7)
   {
    a=a*x;
    s=s+a/i;
    i=i+1;
   }
  cout << "по циклу While s=" << s << endl;
}

void MyDoWhile()
{
	int i;
  float x,s,a;
x=1;
  s=0;
  a=1;
  i=1;
  do
   {
    a=a*x;
    s=s+a/i;
    i=i+1;
   }
  while (i<=7);
  cout << "по циклу Do While s=" << s << endl;
}



int main()
{
	MyFor();
	MyWhile();
	MyDoWhile();

}