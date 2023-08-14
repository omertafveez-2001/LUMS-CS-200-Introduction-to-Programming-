/*

INTRODUCTION 

abstraction: generalisation/simplification of attributes and operations (=> Methods in OOP)
Encapsulation: the process of putting all the items in a box.
Polymorphism: Phenomenon of existing in many forms.
inheritance: Parent:child relationship.

by default class is private and struct is public.

*/

#include <iostream>
using namespace std;

class BondEnergy
{
    private:
        string bondname;
        int bondenergy;
        float bondlength;
    public:
        void setBondName(string n);
        void setBondEnergy(int n);
        void setBondLength(float a);
        void printData();
        // we do not define the function as inline functions. Although it optimized the code, it still risks the security concerns
        // such as importing the header file and changing the code.
};

void BondEnergy::setBondName(string n)
{
    bondname = n;
}

void BondEnergy::setBondEnergy(int n)
{
    bondenergy = n;
}

void BondEnergy::setBondLength(float n)
{
    bondlength = n;
}

void BondEnergy::printData()
{
    cout << "Bond's Name: " << bondname << endl;
    cout << "Bond's Energy: " << bondenergy << endl;
    cout << "Bond' Length: " << bondlength << endl;
}

int main()
{
    BondEnergy be1;
    //be1.bondname = "C|H"; 
    // The above code results in the error => string BondEnergy::bondname' is private within this context
    // because the variables declared private cannot be accessed explicitly. That is why need setters and getters.
    string name;
    int energy;
    float length;

    cout << "Name: ";
    cin >> name;
    cout << "Energy: ";
    cin >> energy;
    cout << "Length: ";
    cin >> length;

    be1.setBondName(name);
    be1.setBondLength(length);
    be1.setBondEnergy(energy);
    be1.printData();
}