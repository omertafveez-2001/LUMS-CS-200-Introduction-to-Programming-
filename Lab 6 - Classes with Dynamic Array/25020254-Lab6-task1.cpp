#include <iostream>
using namespace std;

class BankAccount
{
    private:
        string fnamecustomer;
        string snamecustomer;
        long long int accountnumber;
        string accounttype;
        int balance;
        int count = 0;
    public:
        BankAccount();
        BankAccount(string f, string s, long long int an, string at, int balance);
        void setFirstName(string s);
        void setSecondName(string n);
        void setNumber(long long int n);
        void setAccountType(string t);
        void setBalance(int b);

        string getFirst();
        string getSecond();
        long long int getNumber();
        string getType();
        int getBalance();
        int getCount();
};

int BankAccount::getCount()
{
    return count;
}

BankAccount::BankAccount()
{
    fnamecustomer="\0";
    snamecustomer = "\0";
    accountnumber = 0;
    accounttype = "\0";
    balance = 0;
}

BankAccount::BankAccount(string f, string s, long long int an, string at, int b)
{
    fnamecustomer=f;
    snamecustomer = s;
    accountnumber = an;
    accounttype = at;
    balance = b;
    count++;
}

void BankAccount::setFirstName(string s)
{
    fnamecustomer = s;
}

void BankAccount::setSecondName(string s)
{
    snamecustomer=s;
}
void BankAccount::setNumber(long long int n)
{
    accountnumber = n;
}
void BankAccount::setAccountType(string n)
{
    accounttype = n;
}
void BankAccount::setBalance(int b)
{
    balance = b;
}

string BankAccount::getFirst()
{
    return fnamecustomer;
}

string BankAccount::getSecond()
{
    return snamecustomer;
}

long long int BankAccount::getNumber()
{
    return accountnumber;
}

int BankAccount::getBalance()
{
    return balance;
}

string BankAccount::getType()
{
    return accounttype;
}
class BankManagement
{
    private:
        BankAccount *Management;
        int size;
    public:
        BankManagement();
        BankManagement(int s);
        void addBankAccount();
        void withdrawMoney();
        int checkBalance();
        void changeCustomerName();
        void deleteBankAccount(int n);
        void displayLog();
};

BankManagement::BankManagement()
{
    Management = NULL;
    size = 0;
}

BankManagement::BankManagement(int s)
{
    size = s;
    Management = new BankAccount[size];
}

void BankManagement::addBankAccount()
{
    string first, second,accountype;
    long long int anumber;
    int balance;
    bool flag = false;
    while(!flag)
    {
        cout << "Enter Bank Account:";
        cin >> anumber;
        for(int i = 0; i <size;i++)
        {
            if(Management[i].getNumber()!=anumber)
            {
                Management[Management->getCount()+1].setNumber(anumber);
                flag = true;
                break;
            }
            else
            {
                cout << "Account Exists. Try Again" << endl;
                break;
            }
        }
    }
    cout << "Enter First Name: ";
    cin >> first;
    Management[Management->getCount()+1].setFirstName(first);
    cout << "Enter Second Name: ";
    cin >> second;
    Management[Management->getCount()+1].setSecondName(second);
    cout << "Enter Account Type: ";
    cin >> accountype;
    Management[Management->getCount()+1].setAccountType(accountype);
    cout << "Enter Balance: ";
    cin >> balance;
    Management[Management->getCount()+1].setBalance(balance);
}

void BankManagement::withdrawMoney()
{
    int an;
    cout << "Enter the account number:";
    cin >> an;
    for(int i = 0; i<size;i++)
    {
        if(Management[i].getNumber()==an)
        {
            int b;
            cout << "Enter Withdraw Money" << endl;
            cin >> b;
            int b1 = Management[i].getBalance() - b;
            Management[i].setBalance(b1);
            cout << "Transaction Successful" << endl;
            break;
        }
        else
        {
            cout << "User not found" << endl;
        }
    }
}

int BankManagement::checkBalance()
{
    int an;
    cout << "Enter the account number:";
    cin >> an;
    for(int i = 0; i<size;i++)
    {
        if(Management[i].getNumber()==an)
        {
            return Management[i].getBalance();
        }
    }
    return 0;
}

void BankManagement::displayLog()
{
    for(int i = 0; i < size; i++)
    {
        cout << "First Name: " << Management[i].getFirst() << '\t' << "Second Name: " << Management[i].getSecond()  << "\t" << "Account Number: " << Management[i].getNumber()
        << "\t" << "Account type: " << Management[i].getType() << "\t" << "Balance: " << Management[i].getBalance() << endl;
    }
}

void BankManagement::changeCustomerName()
{
    int an;
    cout << "Bank Account Number: ";
    cin >> an;
    for(int i = 0; i<size; i++)
    {
        if(Management[i].getNumber()==an)
        {
            string f, s;
            cout << "Enter First Name:";
            cin >> f;
            Management[i].setFirstName(f);
            cout << "Enter Second Name: ";
            cin >> s;
            Management[i].setSecondName(s);
            cout << "Name Changed Successfully";
        }
        else
        {
            cout << "Account does not exist" << endl;
        }
    }
}


int main()
{
    BankAccount b1("Omer", "Tafeez", 12345678901234556, "currentaccount", 2500);
    BankManagement m1(5);
    m1.addBankAccount();
}