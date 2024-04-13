#include <iostream>

using namespace std;

namespace loop
{
int NodFor(int, int);
int NodWhile(int, int);
void Output(string, int);
int Input();
}

int main()
{
    int a, b;
    a = loop::Input();
    b = loop::Input();

//     cout << "a = ";
//     cin >> a;
//     cout << "b = ";
//     cin >> b;

   int rez = loop::NodFor(a, b);
   loop::Output("NOD in for = ", rez);

   rez = loop::NodWhile(a, b);
   loop::Output("NOD in while = ", rez);

    return 0;
}

int loop::NodFor(int a, int b)
{
    for (a, b; a != b; )
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
return a;
}

int loop::NodWhile(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
return a;
}

void loop::Output(string out, int rez)
{
   cout << out << rez << endl;
}

int loop::Input()
{
    int a;
    cout << "Введите параметр: ";
    cin >> a;
    return a;
}
