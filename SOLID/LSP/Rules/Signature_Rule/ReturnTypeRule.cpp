#include <iostream>
using namespace std;

// Return Type Rule :
// Subtype overriden method return type should be either identical
// or narrower then the parent method's return type.
// This is also called as return type covariance.
// C++ enforces this by covariance.

class Animal
{
};

class Dog : public Animal
{
};

class Parent
{
public:
    virtual Animal *getAnimal()
    {
        cout << "Parent:Returning Animal Instance" << endl;
        return new Animal();
    }
};

class Child : public Parent
{
public:
    Dog *getAnimal() override
    {
        cout << "Child: Returning Dog Instance" << endl;
        return new Dog();
    }
};

class Client
{
private:
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }

    void takeAnimal()
    {
        p->getAnimal();
    }
};

int main()
{
    Parent *parent = new Parent();
    Child *child = new Child();

    Client *client = new Client(child);
    client->takeAnimal();

    return 0;
}
