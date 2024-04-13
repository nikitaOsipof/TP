#include <iostream>
#include <string>
using namespace std;

enum AccountType { Checking, Deposit };

struct BankAccount   
{
    string name;
    int period;
    double price;
    AccountType acType;
};


int main()
{
	BankAccount goldAccount;
    goldAccount.name = "Gold";
    goldAccount.period = 8;
    goldAccount.price = 6.5;
    goldAccount.acType = Checking;

    BankAccount MyAc = {"Basic", 10, 1.6, Deposit};

    cout << "Hello, BankAccount: ";
	cout << MyAc.name << "; Period: " <<  MyAc.period << endl;   
	cout << goldAccount.name << "; Period: " << goldAccount.period << endl;
}
