#include <iostream>
#include <vector>

using namespace std;

class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawalOnlyAccount : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawalOnlyAccount
{
private:
    double balance;

public:
    SavingsAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawalOnlyAccount
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class FixedTermAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    FixedTermAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

class BankClient
{
private:
    vector<DepositOnlyAccount *> depositOnlyAccounts;
    vector<WithdrawalOnlyAccount *> withdrawableAccounts;

public:
    BankClient(vector<DepositOnlyAccount *> depositOnlyAccounts, vector<WithdrawalOnlyAccount *> withdrawableAccounts)
    {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions()
    {
        for (WithdrawalOnlyAccount *account : withdrawableAccounts)
        {
            account->deposit(1000);
            account->withdraw(500);
        }

        for (DepositOnlyAccount *account : depositOnlyAccounts)
        {
            account->deposit(2000);
        }
    }
};

int main()
{
    vector<WithdrawalOnlyAccount *> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount *> deopsitOnlyAccounts;
    deopsitOnlyAccounts.push_back(new FixedTermAccount());

    BankClient *client = new BankClient(deopsitOnlyAccounts, withdrawableAccounts);
    client->processTransactions();
    return 0;
}