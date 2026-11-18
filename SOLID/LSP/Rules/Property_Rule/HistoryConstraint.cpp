#include <iostream>
using namespace std;

// Sub class methods should not be allowed state changes What
// Base class never allowed.

class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
        {
            throw invalid_argument("Balance cannot be negative");
        }
        balance = b;
    }

    // History Constraint withdrawal should be allowed
    virtual void withdraw(double amount)
    {
        if (balance < amount)
        {
            throw runtime_error("Insufficient funds");
        }
        balance -= amount;
        cout << "Amount withdrawn. Remaining Balance is: " << balance << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    FixedDepositAccount(double b) : BankAccount(b) {}
    // LSP break, History constraint violation
    // Parent class behaviour change: Now withdraw is not allowed.
    // This class will brake client code that relies on withdraw.

    void withdraw(double amount) override
    {
        throw runtime_error("Withdraw not allowed from Fixed Deposit Account");
    }
};

int main()
{
    BankAccount *account = new BankAccount(1000);
    account->withdraw(500);
}