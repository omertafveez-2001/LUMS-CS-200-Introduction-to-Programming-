#include <iostream>
#include <string>
using namespace std;

struct BondEnergy 
{
    string bondtype;
    int bondenergy;
    double bondlength;
};


int main()
{
    const int size = 2;
    struct BondEnergy bondclass[2];
    for (int i = 0; i < size;i++)
    {
        cout << "Enter Bond Type " << i+1 << ": " << endl;
        cin >> bondclass[i].bondtype;
        cout << "Enter Bond Energy " << i+1 << ": " << endl;
        cin >> bondclass[i].bondenergy;
        cout << "Enter Bond Length " << i+1 << ": " << endl;
        cin >> bondclass[i].bondlength;
    }
    string input;
    cout << "Enter information:";
    cin >> input;
    bool flag = false;
    for (int a = 0; a<size; a++)
    {
        if (input==bondclass[a].bondtype)
        {
            cout << bondclass[a].bondtype << " " << bondclass[a].bondenergy << " " << bondclass[a].bondlength << endl;
            flag = true;
        }
        else if (stoi(input)==bondclass[a].bondenergy)
        {
            cout << bondclass[a].bondtype << " " << bondclass[a].bondenergy << " " << bondclass[a].bondlength << endl;
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "No data found" << endl;
    }
}