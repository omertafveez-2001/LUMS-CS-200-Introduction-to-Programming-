#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    cout << "Before assigning a pointer: " << x << endl;
    int *ptr = &x;
    *ptr = 45;
    cout << "After assigning and changing the pointer's address: " << x << endl;
    int *p = ptr;
    cout << endl;
    cout << "Assigning a pointer to another pointer: " << *ptr << endl;
    cout << "Address of the first pointer: " << ptr << "\n" << "Address of the second pointer: " << p << endl;
    cout << endl;
    cout << "Allocating array => Pointer" << endl;
    int arr[5] = {1,2,3,4,5};
    int *ptrr = arr;
    cout << "For loop through pointers (Method 1)" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << ptrr[i];
    }
    cout << endl;
    cout << "For loop through pointer (Method 2) => incrementing the address of the pointer." << endl;
    for(int i = 0; i<5; i++)
    {
        cout << arr[i];
        cout << *ptrr;
        cout << ptrr[i];
        cout << endl;
        ptrr++;
    }

    int *ptrr1 = arr;
    cout << "Array Pointer Duality: Printing the second element of the pointer: " << endl;
    cout << ptrr1[1] << endl;
    cout << *(ptrr1+1) << endl;

    cout << endl;
    cout << "Allocating 2D array Dynamically...." << endl;
    int rows,cols;
    cout << "Enter rows and cols:";
    cin >> rows, cols;
    double ** ptrrr = new double *[rows];
    for(int i = 0; i < rows; i++)
    {
        ptrrr[i] = new double [cols];
    }

    cout << endl;
    cout << "Allocation completed..." << endl;

    cout << endl;
    cout << "Deleting the matrix..." << endl;

    for(int i = 0; i<rows; i++)
    {
        delete [] ptrrr[rows];
    }
    delete [] ptrrr;

    cout << "Deleted successfully..." << endl;
}