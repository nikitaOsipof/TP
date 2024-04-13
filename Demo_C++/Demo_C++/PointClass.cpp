#include <iostream>
#include <math.h>

using namespace std;

class Point
{
private:
    double x;
    double y;
public:
    Point()
    {
      x = 1;
      y = 1;
      }
    Point(double px, double py)
    {
        x = px;
        y = py;
    }

    double DistToPoint(Point p)
    {
        double d = sqrt((p.x - x)*(p.x - x)+(p.y - y)*(p.y - y));
        return d;
    }
};

int main() {
    double x,y;
  x = 12;
  y = 10;
  Point p1(x,y);
  Point P0;
  double d = P0.DistToPoint(p1);
  Point* p3 = new Point(5,5);
   double d2 = p3->DistToPoint(p1);
   delete p3;
   p3 = new Point(55,66);
  return 0;
}