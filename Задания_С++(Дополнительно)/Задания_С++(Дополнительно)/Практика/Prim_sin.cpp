#include <iostream>
#include <math.h>

using namespace std; 


int main()
{
	double x,y; 
	cout<<"\tx\tsin(x)\n";

	x = 0;
	do
	{
		y = sin(x);
		cout <<"\t"<< x <<"\t"<< y <<endl;
		x = x + 0.01;

	} 
	while (x <= 3.14/2);

return 0;

}