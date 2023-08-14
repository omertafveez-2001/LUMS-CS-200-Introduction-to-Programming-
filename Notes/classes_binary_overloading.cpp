/*
OVERLOADING BINARY OPERATORS => ++, --, []
*/

#include <iostream>
using namespace std;

class Counter
{
    private:
        int count;
    public:
        Counter();
        int getCounter();
        friend ostream& operator<<(ostream& out, const Counter &rhs);
        Counter operator++();
        Counter operator++(int a);
};

Counter::Counter()
{
    count = 0;
}

Counter Counter::operator++()
{
    count+=1;
    return *this;
}

Counter Counter::operator++(int a)
{
    a=a;
    Counter c = *this;
    count++;
    return c;
}

class SafeArray
{
    private:
        int size;
        int *p;
    public:
        SafeArray();
        ~SafeArray();
        SafeArray(int n);
        SafeArray(int arr[], int si);
        SafeArray(const SafeArray&rhs);
        void setSize(int n);
        int getSize();
        friend ostream& operator<<(ostream& our, const SafeArray &rhs);
        void operator=(const SafeArray &rhs);
        int& operator[](int i); //writing
        int operator[](int i)const; //reading
};

int& SafeArray::operator[](int i)
{
    return p[i];
}

int SafeArray::operator[](int i)const
{
    return p[i];
}

SafeArray::SafeArray()
{
    size = 0;
    p = nullptr;
}

SafeArray::~SafeArray()
{
    delete [] p;
}

SafeArray::SafeArray(int n)
{
    size = 0;
    p = new int [size];
}

SafeArray::SafeArray(int arr[], int si)
{
    size = si;
    p = new int [size];
    for(int i = 0; i < size; i++)
    {
        p[i] = arr[i];
    }
}

SafeArray::SafeArray(const SafeArray &rhs)
{
    size = rhs.size;
    p = new int [size];
    for(int i = 0; i<size; i++)
    {
        p[i] = rhs.p[i];
    }
}

void SafeArray::setSize(int n)
{
    size = n;
}

int SafeArray::getSize()
{
    return size;
}

ostream& operator<<(ostream& out, const SafeArray &rhs)
{
    for(int i = 0; i<rhs.size;i++)
    {
        out << rhs.p[i];
    }
    return out;
}

void SafeArray::operator=(const SafeArray &rhs)
{
    size = rhs.size;
    p = new int [size];
    for (int i = 0; i<rhs.size; i++)
    {
        p[i] = rhs.p[i];
    }
}

int main()
{
    int const sizing = 3;
    int arr[sizing] = {1,2,3};
    SafeArray c1(arr, sizing);
    cout << "Shallow Copy: " << endl;
    cout << c1 << endl;
    SafeArray c2(c1);
    cout << "Deep copy constructor: " << endl;
    cout << c2 << endl;
    SafeArray c3;
    c3=c2;
    cout << "Assignment overloaded: " << endl;
    cout << c3 << endl;
    c3[1] = 4;
    cout << "[] Writing overloaded: " << endl;
    cout << c3 << endl;
    int x = c3[0];
    cout << "[] reading overloaded: " << endl;
    cout << x << endl;
}