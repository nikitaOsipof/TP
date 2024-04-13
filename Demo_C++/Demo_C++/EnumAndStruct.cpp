#include <iostream>
#include <string>

using namespace std;

enum AccountType { Checking, Deposit };

struct BankAccount   // structure declaration
{
    string name;
    float period;
    double price;
    AccountType acType;
};

int main()
{
    BankAccount goldAccount;
    goldAccount.name = "Gold";
    goldAccount.period = 12.5;
    goldAccount.price = 6.5;
    goldAccount.acType = Checking;

    BankAccount MyAc =
    {
        "Basic",
        10,
        6,
        Deposit
    };

    cout << "Hello BankAccount " << goldAccount.name << endl;
    cout << "Hello BankAccount " << MyAc.name << endl;
    return 0;
}

