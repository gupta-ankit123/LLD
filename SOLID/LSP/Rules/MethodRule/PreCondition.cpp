#include <iostream>
using namespace std;

// A Precondition must be statisfied before a method can be executed.
// Sub classes can weaken the precondition but cannot strengthen it.

class User
{
public:
    // PreCondition: Password must be 8 characters long
    virtual void setPassword(string password)
    {
        if (password.length() < 8)
        {
            throw invalid_argument("Password must be 8 characters long");
        }
        cout << "Password set successfully" << endl;
    }
};

class AdminUser : public User
{
public:
    // Precondition: Password must be 6 characters long
    void setPassword(string password) override
    {
        if (password.length() < 6)
        {
            throw invalid_argument("Password must be at least 6 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

int main()
{
    User *user = new AdminUser();
    user->setPassword("126781"); // Works fine: AdminUser allows shorter passwords

    return 0;
}