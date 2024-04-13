// Example program
#include <iostream>
#include <string>
#include <math.h>

class Point
{
 private:
    double x;
    double y;
public:
    Point()
    {}
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
    
    void Set(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    
};

int main()
{
  Point p;
  p.Set(12,44);
//  p.x = 12;
//  p.y = 44;;

}
