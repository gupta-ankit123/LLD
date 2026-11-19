#include <iostream>
#include <stdexcept>

using namespace std;

class TwoDimensionalShape
{
public:
    virtual double area() = 0;
};

class ThreeDimensionalShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDimensionalShape
{
private:
    double side;

public:
    Square(double s) : side(s) {}
    double area() override
    {
        return side * side;
    }
};

class Rectangle : public TwoDimensionalShape
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
};

class Cube : ThreeDimensionalShape
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

int main()
{
    Square *square = new Square(5);
    Cube *cube = new Cube(3);

    cout << "Square area: " << square->area() << endl;
    cout << "Cube volume: " << cube->area() << endl;
}
