#include <iostream>
using namespace std;

class Car
{
protected:
    int speed;

public:
    Car()
    {
        speed = 0;
    }
    void accelerate()
    {
        cout << "Car is accelerating" << endl;
        speed += 20;
    }

    // PostCondition: Speed should not reduce after braking
    virtual void brake()
    {
        cout << "Applying brakes" << endl;
        speed -= 20;
    }
};

// Subclass can strengthen postcondition - Does not violate LSP
class HybridCar : public Car
{
private:
    int charge;

public:
    HybridCar() : Car()
    {
        charge = 0;
    }

    // PostCondition : Speed must reduce after brake
    // PostCondition : Charge must increase.
    void brake() override
    {
        cout << "Applying brakes" << endl;
        cout << "Charging........" << endl;
        speed -= 20;
        charge += 10;
    }
};

int main()
{
    Car *car = new HybridCar();
    car->accelerate();
    car->accelerate();
    car->brake();
}