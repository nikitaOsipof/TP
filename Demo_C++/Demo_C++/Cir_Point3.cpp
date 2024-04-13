#include <iostream>
#include <math.h>

using namespace std;

class Point
{
  protected:
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
};

class Circle
{
private:
    Point p1;
    Point p2;
public:
    Circle(Point p0, Point pd)
    {
        p1 = p0;
        p2 = pd;
    }

    double Sq()
    {
        double s = p1.DistToPoint(p2)*p1.DistToPoint(p2)*3.14;
        return s;
    }
};

class Point3D : public Point
{
private:
  double  z;
public:

    Point3D(double px, double py, double pz)
    {
        x = px;
        y = py;
        z = pz;
    }

    double DistToPoint(Point3D p)
    {
        double d = sqrt((p.x - x)*(p.x - x)+(p.y - y)*(p.y - y)+(p.z - z)*(p.z - z));
        return d;
    }
};

int main()
{
    double x,y;
    cout << "Центр окружности" << endl;
    cin >> x;
    cin >> y;
    Point p1(x,y);
    Point p0;
    cout << "Точка на дуге" << endl;
    cin >> x;
    cin >> y;
    Point p2(x,y);

    cout << "Окружности" << endl;
    Circle cir1(p1,p2);
    double S1 = cir1.Sq();

    Circle cir2(p0,p2);
    double S2 = cir2.Sq();
    cout << "Площадь окружности 1" << S1 << endl;
    cout << "Площадь окружности 2" << S2 << endl;

    double z;
    cout << "Добавьте две z для трехмерных точек" << endl;
    cin >> z;
    Point3D p3D(x,y,z);
    cin >> z;
    Point3D p3D1(x,y,z);
    double R = p3D1.DistToPoint(p3D);
    cout << "R 3D = " << R << endl;
    return 0;
}

