#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x;
    double y;
};

double DistToPoint(Point p1, Point p2)
{
    double d = sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
    return d;
}

int main()
{
    Point p1, p2;
    cout << "Input first point" << endl;
    cin >> p1.x;
    cin >> p1.y;
    cout << "Input second point" << endl;
    cin >> p2.x;
    cin >> p2.y;
    double S = DistToPoint(p1,p2)*DistToPoint(p1,p2)*3.14;
    cout << "Dist to point = " << S << endl;
    return 0;
}

