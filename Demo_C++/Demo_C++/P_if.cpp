#include <iostream>
#include <windows.h>
using namespace std;
void main()
{SetConsoleOutputCP(1251);
   int x, y;
    cin >> x >> y;
    if (x > 0)
    {
        if (y > 0)   // x>0, y>0
        {
            cout << "Первая четверть" << endl;
        }
        else            // x>0, y<0
        {
            cout << "Четвертая четверть" << endl;
        }
    }
    else
    {
        if (y > 0)   // x<0, y>0
        {
            cout << "Вторая четверть" << endl;
        }
        else            // x<0, y<0
        {
            cout << "Третья четверть" << endl;
        }
    }

}
