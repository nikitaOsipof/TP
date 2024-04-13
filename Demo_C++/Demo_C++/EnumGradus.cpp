#include <iostream>

using namespace std;

enum gradus
{
    minn = 0,
    krit = 50,
    maxx = 100
};

int main()
{

	//int sum = 0; // попробуйте без начальной инициализации
 //   for (int i = 0; i<5; i++)
 //   {
 //       sum++;
 //   }
 //   cout << sum;

    gradus tg;
    tg = maxx;
    int t = 55;
    if (t < tg)
    cout << "work"<< endl;
    else
    cout << "not work"<< endl;

    return 0;
}

