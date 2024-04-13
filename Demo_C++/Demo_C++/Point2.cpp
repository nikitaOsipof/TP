#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x;
    double y;

    double DistToPoint(Point p)
    {
        double d = sqrt((p.x - x)*(p.x - x)+(p.y - y)*(p.y - y));
        return d;
    }
};

int main()
{
    Point p1, p2;

    cin >> p1.x;
    cin >> p1.y;

    cin >> p2.x;
    cin >> p2.y;
    double S = p1.DistToPoint(p2)*p1.DistToPoint(p2)*3.14;
    cout << "S =  " << S << endl;
    return 0;
}

