#include <iostream>
using namespace std;

// important to note that the structs are stored and created on stack.
// Structs has multiple variables of different types but has no member function.


//creating a struct bondenergy1.
struct BondEnergy1
{
    string bondtype;
    int bondenergy;
    double bondlegnth;
};

//creating a struct bondenergy2
struct BondEnergy2
{
    string bondtype[2];  //size of this variable is 2*24 = 48
    int bondenergy[2];   //size of this variable is 2*4 = 8
    double bondlength[2]; // size of this variable is 2*8 = 16
};

int main()
{
    //declaring structs variables
    struct BondEnergy1 be1;
    struct BondEnergy2 be2;
    struct BondEnergy1 be3[2];

    // initializing
    be1.bondtype = "C|H";
    be2.bondtype[0] = "C|H";
    be3[0].bondtype = "C|H";
    be3[0].bondlegnth=1.456;

    // another implementation
    struct BondEnergy1 be4 = {"C|H", 22, 1.6789};
    cout << "The bond type stored in be4 is: " << be4.bondtype << endl;
    cout << "The bond length stored in the first element of be3 is: " << be3[0].bondlegnth << endl;
}
