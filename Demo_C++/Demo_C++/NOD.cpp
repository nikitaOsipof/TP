#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "Hello NOD in for!" << endl;

    for (a, b; a != b; )
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    cout << a << endl;

    cout << "Hello NOD in while!" << endl;

    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    cout << a << endl;
    return 0;
}

