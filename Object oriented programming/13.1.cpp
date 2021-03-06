#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
class Point
{
protected:
    double x;
    double y;

public:
    Point(double X = 0.0, double Y = 0.0);
};
class Circle : public Point
{
protected:
    double r;
    double circumference;
    double area;

public:
    Circle(double X = 0, double Y = 0, double R = 0);
    void show();
};
class Cylinder : public Circle
{
private:
    double h;
    double surfacearea;
    double volume;

public:
    Cylinder(double X = 0, double Y = 0, double R = 0, double H = 0);
    void show();
};
Point::Point(double X, double Y)
{
    x = X;
    y = Y;
}
Circle::Circle(double X, double Y, double R) : Point(X, Y)
{
    r = R;
    circumference = 2 * M_PI * r;
    area = M_PI * pow(r, 2);
}
void Circle::show()
{
    cout << "The circumference is: " << setiosflags(ios::fixed) << setprecision(2) << circumference << endl
         << "The area is: " << setiosflags(ios::fixed) << setprecision(2) << area << endl;
}
Cylinder::Cylinder(double X, double Y, double R, double H) : Circle(X, Y, R)
{
    h = H;
    surfacearea = circumference * h + 2 * area;
    volume = area * h;
}
void Cylinder::show()
{
    cout << "The surfacearea is: " << setiosflags(ios::fixed) << setprecision(2) << surfacearea << endl
         << "The volume is: " << setiosflags(ios::fixed) << setprecision(2) << volume << endl;
}
int main()
{
    Circle test2(3, 4, 5);
    test2.show();
    Cylinder test3(3, 4, 5, 1);
    test3.show();
    return 0;
}