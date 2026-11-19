#include <iostream>
#include <stdexcept>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// This is the violation of Interface Segregation Principle (ISP) because the Shape interface has methods
// that are not applicable to all shapes.For example, a square does not have a volume, but it is forced to implement
// the volume() method.
class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        throw runtime_error("Volume not applicable for square");
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override
    {
        return length * width;
    }
    double volume() override
    {
        throw runtime_error("Volume not applicable for rectangle");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override
    {
        return 6 * side * side;
    }
    double volume() override
    {
        return side * side * side;
    }
};
// This is why the Interface Segregation Principle (ISP) is important. We can create separate interfaces for 2D and 3D shapes,
// so that classes only implement the methods that are applicable to them.
//  It states that clients should not be forced to depend on interfaces they do not use.
// In this case, the Shape interface has methods that are not applicable to all shapes, which violates the ISP.
int main()
{
    Square *square = new Square(5);
    Shape *sq = new Square(6);

    cout << "Parent class pointer pointing to child object square area: " << sq->area() << endl;
    cout << "Child class pointer pointing to child object square area: " << square->area() << endl;
    cout << "Volume of square: " << square->volume() << endl;
}