#include <iostream>
using namespace std;

class SafeArray
{
    public:
        int size;
        int* ptr;
    public:
        SafeArray(); //default constructor
        SafeArray(int s); //size constructor
        SafeArray(int a[], int s); //shallow copy
        SafeArray(const SafeArray &rhs); //deep copy

        int& operator[](int index); 
        int operator[](int index)const;
        SafeArray operator=(const SafeArray &rhs);
        friend ostream& operator<<(ostream& out, const SafeArray &rhs);

        SafeArray operator++();
        SafeArray operator++(int a);

        SafeArray operator+(const SafeArray &rhs);


        ~SafeArray();
};

SafeArray SafeArray::operator+(const SafeArray &rhs)
{
    SafeArray t;
    t.size = rhs.size;
    t.ptr = new int [size];
    for (int i ; i < size; i++)
    {
        t.ptr[i] = ptr[i] + rhs.ptr[i];
    }
    return t;

}

SafeArray SafeArray::operator++()
{
    for(int i = 0; i < size; i++)
    {
        ptr[i]++;
    }
    return *this;
}

SafeArray SafeArray::operator++(int a)
{
    a=a;
    SafeArray t = *this;
    for (int i = 0; i < size; i++)
    {
        ptr[i]++;

    }
    return t;
}
SafeArray::~SafeArray()
{
    if(ptr!=NULL)
    {
        delete [] ptr;
    }
}
SafeArray::SafeArray()
{
    size = 0;
    ptr = NULL;
}

SafeArray::SafeArray(int s)
{
    size = s;
    ptr = new int[size];
}

SafeArray::SafeArray(int a[], int s)
{
    size = s;
    ptr = new int[size];
    for (int i =0; i < size; i++)
    {
        ptr[i] = a[i];
    }
}

SafeArray::SafeArray(const SafeArray &rhs)
{
    size = rhs.size;
    ptr = new int[size];
    for (int i =0; i < size; i++)
    {
        ptr[i] = rhs.ptr[i]; 
    }
}

int& SafeArray::operator[](int index)
{
    return ptr[index];
}

int SafeArray::operator[](int index)const
{
    return ptr[index];
}

SafeArray SafeArray::operator=(const SafeArray &rhs)
{
    if (rhs.ptr==NULL)
    {
        cout << "invalid" << endl;
    }
    else{
    size = rhs.size;
    ptr = new int[size];
    for (int i =0; i < size; i++)
    {
        ptr[i] = rhs.ptr[i];
    }
    }
}

ostream& operator<<(ostream& out, const SafeArray &rhs)
{
    for(int i=0; i<rhs.size; i++)
    {
        out << rhs.ptr[i] << endl;
    }
    return out;
}

int main()
{
    SafeArray c1(5);
    int arr[5] = {1,2,3,4,5};
    SafeArray c2(arr, 4); //shallow copy
    cout << "Shallow copy: " << c2;
    SafeArray c3(c2); //deep copy
    cout << "Deep Copy: " << c3;
    SafeArray c4 = c3; //assignment operator;
    cout << "Assignment Operator: " << c4;
    c4[2] = 6;
    int y = c4[1];
    cout << "[] overloaded: " << c4 << y << endl;
    SafeArray c5 = ++c4;
    cout << "operator++ overload:\n" << c5 << endl;
    SafeArray c6 = c5++;
    cout << "operator++ overloaded 2:\n" << c6 << endl;
    SafeArray c7 = c5+c4;
    cout << "Addition:\n" << c7 << endl;
    SafeArray c8, c9;
    c8 = c9;
    cout << "Invalid Null:" << c8 << endl;
}