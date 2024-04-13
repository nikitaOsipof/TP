#include <iostream>


using namespace std;

void sum(int); 		// пpототип функции
double sum2(int);

int s = 0; 		// глобальна€ переменна€



int main()
{
    int i, b, k;  		// локальные переменные
    double s = 0;
    cout << "\n¬ведите число слагаемых ";
    cin >> k;

    for (i=0; i<k; i++)
    {  cout << "\n¬ведите новое слагаемое ";
        cin >> b;
        sum(b);  		// вызов функции
        s = sum2(b);
    }
       cout << "\ns = " << ::s; // доступ к глобальной переменной
       cout << "\ns = " << s;

       return 0;
}

void sum(int c)
{
    s = s + c;
}

double sum2(int c)
{
  static double ss;
  ss = ss + c;
    return ss;
}
