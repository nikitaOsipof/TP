#include <iostream>
#include <math.h>

using namespace std;


double Sq(double);
void Output(double);
double Input();

int main()
{
	double p = Input();
	//cout << "Input p:\n";   
	//cin >> p;    
////	вычисление стороны
//	double st = p/3;
//
// вычисление площади
//	double s = sqrt(p/2*(p/2-st)*(p/2-st)*(p/2-st));
	double s = Sq(p);
//	cout << "s = " << s << endl;
	Output(s);
	return 0;
}

double Sq(double p)
{
    double st = p/3;
    double s = sqrt(p/2*(p/2-st)*(p/2-st)*(p/2-st));
    return s;
}

void Output(double s)
{
	cout << "s = " << s << endl;
}

double Input()
{
	double p;
	cout << "Input p:\n";   
	cin >> p; 
	return p;
}