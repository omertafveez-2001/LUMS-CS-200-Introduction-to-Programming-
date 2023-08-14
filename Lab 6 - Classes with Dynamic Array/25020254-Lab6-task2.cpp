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
        int count=0;
        BankManagement();
        BankManagement(int s);
        void addBankAccount();
        void withdrawMoney();
        int checkBalance();
        void changeCustomerName();
        void deleteBankAccount(int n);
        void displayLog();
        friend ostream& operator<<(ostream& out, const BankManagement &rhs);
        friend istream& operator>>(istream& in, BankManagement &rhs);
        BankAccount operator[](int n)const;
        BankAccount operator[](int n);
        void displayUpToThisLimit(int n);
    
};

void BankManagement::displayUpToThisLimit(int n)
{
    for(int i = 0; i < count; i++)
    {
        if(Management[i].getBalance()<=n)
        {
            cout << "First Name: " << Management[i].getFirst() << "\t" << "Second Name: " << Management[i].getSecond()  << "\t" << "Account Number: " << Management[i].getNumber()
            << "\t" << "Account type: " << Management[i].getType() << "\t" << "Balance: " << Management[i].getBalance() << endl;
        }
    }
}

BankAccount BankManagement::operator[](int n)
{
    return Management[n];
}

BankAccount BankManagement::operator[](int n)const
{
    return Management[n];
}

istream& operator>>(istream& in, BankManagement &rhs)
{
    string first, second,accountype;
    long long int anumber;
    int balance = 600000;
    bool flag = false;
    while(!flag)
    {
        cout << "Enter Bank Account:";
        in >> anumber;
        for(int i = 0; i <rhs.count;i++)
        {
            if(rhs.Management[i].getNumber()!=anumber)
            {
                rhs.Management[rhs.count].setNumber(anumber);
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
    in >> first;
    rhs.Management[rhs.count].setFirstName(first);
    cout << "Enter Second Name: ";
    in >> second;
    rhs.Management[rhs.count].setSecondName(second);
    cout << "Enter Account Type: ";
    in >> accountype;
    rhs.Management[rhs.count].setAccountType(accountype);
    while(balance>55000)
    {
        cout << "Enter Balance: ";
        in >> balance;
        if(balance<=55000)
        {
            rhs.Management[rhs.count].setBalance(balance);
        }
        else
        {

            cout << "Balance exceeds 55000. Try Again" << endl;
        }
    }
    rhs.count++;
    return in;
}
ostream& operator<<(ostream& out, const BankManagement &rhs)
{
    for(int i = 0; i<rhs.count;i++)
    {
        out << "First Name: " << rhs.Management[i].getFirst() << "\t" << "Last Name: " << rhs.Management[i].getSecond() << "\t" << "Account Number: " << rhs.Management[i].getNumber() <<
        "\t" << "Account type: " << rhs.Management[i].getType() << "\t" << "Balance: " << rhs.Management[i].getBalance() << endl;
    }
    return out;
}

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
    int balance = 600000;
    bool flag = false;
    while(!flag)
    {
        cout << "Enter Bank Account:";
        cin >> anumber;
        for(int i = 0; i <count;i++)
        {
            if(Management[i].getNumber()!=anumber)
            {
                Management[count].setNumber(anumber);
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
    Management[count].setFirstName(first);
    cout << "Enter Second Name: ";
    cin >> second;
    Management[count].setSecondName(second);
    cout << "Enter Account Type: ";
    cin >> accountype;
    Management[count].setAccountType(accountype);
    while(balance>55000)
    {
        cout << "Enter Balance: ";
        cin >> balance;
        if(balance<=55000)
        {
            Management[count].setBalance(balance);
        }
        else
        {

            cout << "Balance exceeds 55000. Try Again" << endl;
        }
    }
    count++;
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
        cout << "First Name: " << Management[i].getFirst() << "\t" << "Second Name: " << Management[i].getSecond()  << "\t" << "Account Number: " << Management[i].getNumber()
        << "\t" << "Account type: " << Management[i].getType() << "\t" << "Balance: " << Management[i].getBalance() << endl;
    }
    cout << "hello" << endl;
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
   cout << "Bank Managment System" << endl;
}