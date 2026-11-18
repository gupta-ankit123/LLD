#include <iostream>
using namespace std;

// Method Argument Rule :
// Subtype method arguments can be identical or wider than the supertype
// C++ imposes this by keeping singature identical

class Parent
{
public:
    virtual void print(string msg)
    {
        cout << "Parent" << msg << endl;
    }
};

class Child : public Parent
{
public:
    void print(string msg) override
    {
        cout << "Child" << msg << endl;
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
    void printMsg()
    {
        p->print("Hello");
    }
};

int main()
{
    Parent *parent = new Parent();
    Parent *child = new Child(); // this is upcasting, it is a parent type pointer pointing to a child type object.

    // Client *client = new Client(parent);
    Client *client = new Client(child);
    client->printMsg(); // so here according to the Liskov Substitution Principle, we can use the child class object in place of the parent class object and it will work fine.

    return 0;
}
