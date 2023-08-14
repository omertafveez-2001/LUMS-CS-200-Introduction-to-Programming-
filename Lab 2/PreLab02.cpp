#include <iostream>
using namespace std;

class BondEnergy 
{
    private:
        string bondtype;
        int bondenergy;
        double bondlength;
    
    public:
        void setBondType(string t);
        void setBondEnergy(int e);
        void setBondLength(double l);
        void setBondData(string t, int e, double l);
        void getBondType();
        void getBondEnergy();
        void getBondLength();
        void print();
};

void BondEnergy:: setBondType(string t)
{
    bondtype = t;
}

void BondEnergy:: setBondEnergy(int e)
{
    bondenergy = e;
}

void BondEnergy:: setBondLength(double l)
{
    bondlength = l;
}

void BondEnergy::setBondData(string t, int e, double l)
{
    bondtype = t;
    bondenergy = e;
    bondlength = l;
}
void BondEnergy:: getBondType()
{
    cout << bondtype << endl;
}

void BondEnergy:: getBondEnergy()
{
    cout << bondenergy << endl;
}

void BondEnergy:: getBondLength()
{
    cout << bondlength << endl;
}

void BondEnergy:: print()
{
    cout << bondtype << endl;
    cout << bondenergy << endl;
    cout << bondlength << endl;
}

void testBondEnergy()
{
    string t;
    int e;
    double l;
    cout << "Enter Bond Type:";
    cin >> t;
    cout << "Enter Bond Energy:";
    cin >> e;
    cout << "Enter Bond Length:";
    cin >> l;
    BondEnergy b1;
    b1.setBondData(t, e, l);
    b1.print();
}

int main()
{
    testBondEnergy();
}