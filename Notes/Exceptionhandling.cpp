#include <iostream>
using namespace std;

class NegativeNumber
{
    private:
        string name;
        int den;
        int num;
    public:
        NegativeNumber();
        NegativeNumber(string a);
        string get_string();
};

double Calculateq(int a, int b) throw(NegativeNumber)
{
    if(b == 0)
    {
        throw a;
    }
    return a/b;
}

NegativeNumber::NegativeNumber()
{
    name = "";
}

NegativeNumber::NegativeNumber(string s)
{
    name = s;
}

string NegativeNumber::get_string()
{
    return name;
}

int main()
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    try
    {
        if(name=="Omer")
        {
            throw NegativeNumber(name);
        }
        cout << "Good Job" << endl;
    }
    catch(NegativeNumber e)
    {
        cout << e.get_string() << " is not valid" << endl;
    }

    NegativeNumber n1;
    int a = 10;
    int b = 0;
    try
    {
        cout << Calculateq(a,b) << endl;
    }
    catch(NegativeNumber)
    {
        cout << "Error Handled boss" << endl;
    }
    
}