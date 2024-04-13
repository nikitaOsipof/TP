#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x;
    double y;

    Point()
    {}
    Point(double xd, double yd)
    {
        x = xd;
        y = yd;
    }
};

class Triangle
{
    Point a;
    Point b;
    Point c;

    public:
        Triangle (Point pa, Point pb, Point pc)
        {
            a = pa;
            b = pb;
            c = pc;
        }
        double getArea()
        {
            return abs((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2;
        }
};

int main()
{
    Point a(1,10), b(2,20), c(16,3);
    Triangle tr1(a,b,c);
    double Streug1 = tr1.getArea();

    Triangle tr2({1, 10}, {2, 20}, {16, 3});
    double Streug2 = tr2.getArea();

    cout << "S = " << Streug1 << endl;
    cout << "S = " << Streug2 << endl;
    return 0;
}

