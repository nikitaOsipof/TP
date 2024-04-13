#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x;
    double y;
    char name[4];
};


int main()
{
    Point p1, p2;
    cout << "Input first point" << endl;
    p1.x = 1;
    p1.y = 3;
   // cin >> p1.x;
   // cin >> p1.y;
    cout << "Input second point" << endl;
   // cin >> p2.x;
  //  cin >> p2.y;
  p2.x = 4;
  p2.y = 7;
    double d = sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
    cout << "Dist to point = " << d << endl;
    return 0;
}
