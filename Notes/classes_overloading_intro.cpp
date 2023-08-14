/* 

OVERLOADED OPERATORS AND COPY CONSTRUCTORS

Constructors imply that the the class has its default values upon constructions.
Destructors destroy the class after the system terminates so that the memory being used by the class is emptied.
The main purpose of the destructors is the ensure that the memory in stack is deallocated so the stack does not run out of
out of memory.

COPY CONSTRUCTOR: essentially copies a defined instance's elements into another instance's (object) elements during its
creation. Essentially a shallow copy.

OVERLOADED ASSIGNMENT OPERATOR: This is a bitwise operator when an already initialized object is assigned a new value
from an existing object. Essentially a deep copy using reference operator as the argument. It is useful for references and 
pointers. The values are copied to and fro heap in deep copy. 

DEEP COPY: Allows the programmers to cater the problem of location being out of score which would fail the reference
parameters.

for overloading assignment operators you need
1 - Default constructor
2 - Copy Constructor
3 - Assignment Operator function.

*/
#include <iostream>
using namespace std;


class BondEnergy
{
    private:
        string bondname;
        int bondenergy;
        float bondlegnth;

    public:
    // declaring a default constructor.
    BondEnergy();

    //declaring a copy constructor.
    BondEnergy(const BondEnergy &rhs);

    // declaring overload operators.
    BondEnergy operator=(const BondEnergy &rhs);
    void setData(string n, int a, float b);

    //printing data
    void printData();
};

BondEnergy BondEnergy::operator=(const BondEnergy &rhs)
{
    BondEnergy b;
    b.bondname=rhs.bondname;
    b.bondenergy=rhs.bondenergy;
    b.bondlegnth=rhs.bondlegnth;
    return b;
}
BondEnergy::BondEnergy()
{
    bondname="\0";
    bondenergy = 0;
    bondlegnth = 0;
}
void BondEnergy::setData(string n, int a, float b)
{
    bondname = n;
    bondenergy = a;
    bondlegnth = b;
}

BondEnergy::BondEnergy(const BondEnergy &rhs)
{

    // we can also use this keyword which essentially points to existing object on the lhs.
    bondname = rhs.bondname;
    bondenergy = rhs.bondenergy;
    bondlegnth = rhs.bondlegnth;
}

void BondEnergy::printData()
{
    cout << "Bond's Name: " << bondname << endl;
    cout << "Bond's Energy: " << bondenergy << endl;
    cout << "Bond's Length: " << bondlegnth << endl;
}

int main()
{
    BondEnergy be1;
    be1.setData("C|H", 12345, 12.4);
    BondEnergy be2(be1);
    cout << "Setting Data in first Object: " << endl;
    be1.printData();
    cout << "Setting Data in the second object through copy constructor: " << endl;
    be2.printData();
    BondEnergy be3=be2;
    cout << "Setting Data in the third object through assignment overloading: " << endl;
    BondEnergy *be4 = &be3;
    cout << "Setting Data in the fourth object through assignment overloading and reference: " << endl;
    (*be4).printData();
}