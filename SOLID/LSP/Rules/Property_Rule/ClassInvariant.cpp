#include <iostream>
using namespace std;

// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

// Invariant Rule:Balance can never be negative

class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
        {
            throw invalid_argument("Balance can never be negative");
        }
        balance = b;
    }

    virtual void withdraw(double amount)
    {
        if (amount > balance)
            throw runtime_error("Insufficient Balance");
        balance -= amount;
        cout << "Amount Withdrawn. Remaining balance is" << balance << endl;
    }
};

// Breaks Invariant :Should not be allowed
class CheatAccount : public BankAccount
{
public:
    CheatAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override
    {
        balance -= amount; // LSP breaks negative balance allowed
        cout << "Amount Withdrawn. Remaining balance is" << balance << endl;
    }
};

int main()
{
    CheatAccount *account = new CheatAccount(1000);
    account->withdraw(2200);

    return 0;
}
