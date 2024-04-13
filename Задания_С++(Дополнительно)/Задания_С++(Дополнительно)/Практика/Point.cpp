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


int main()
{
	Point a(1, 10);
	Point d;

	//ShowPoint(a);
	//ShowPoint(d);

	a.ShowPoint();
	d.ShowPoint();

    return 0;
}

