#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x;
    double y;

    Point()
    {
		x = y = 0;
	}
    Point(double xd, double yd)
    {
        x = xd;
        y = yd;
    }

	void ShowPoint()
	{
		cout << x << "-" << y << "\n";
	}
};


//void ShowPoint(Point p)
//{
//	cout << p.x << "-" << p.y << "\n";
//}


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
	Point a(1, 10) , b(21, 25);
	Point d;
	//ShowPoint(a);
	//ShowPoint(d);
	a.ShowPoint();
	d.ShowPoint();

    Triangle tr1(a,b,d);
    double Streug1 = tr1.getArea();
	cout << sizeof(tr1) << endl;

    Triangle tr2({1, 10}, {21, 25}, {0, 0});
    double Streug2 = tr2.getArea();

    cout << "S = " << Streug1 << endl;
    cout << "S = " << Streug2 << endl;
    return 0;
}

