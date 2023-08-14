/*
Note: In counter Example that is overloading operator++ or operator--, we do not use setters, parameterized constructors and
by default is pre incrementation
*/


#include <iostream>
using namespace std;

class Counter
{
    private:
        int count;

    public:
        Counter();
        int getCount();
        Counter operator++();
        Counter operator++(int a);
        friend ostream& operator<<(ostream&out, const Counter &rhs);
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
    count+=1;
    return c;
}

ostream& operator<<(ostream&out, const Counter &rhs)
{
    out << rhs.count << endl;
    return out;
}

int main()
{
    Counter c1, c2, c3;
    c1 = ++c2;
    c3 = c2++;
    cout << c1 << c3 << endl;
}