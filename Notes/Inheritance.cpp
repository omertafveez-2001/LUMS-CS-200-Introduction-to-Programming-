#include <iostream>
using namespace std;

class Base
{
    private:
        int x;
        int y;
    public:
        Base();
        Base(int x, int y);
        Base(const Base &rhs);
        Base operator=(const Base &rhs);
        int getX();
        int getY();
        ~Base();
        virtual void display();
        friend ostream& operator<<(ostream &out, const Base &rhs);
};

ostream& operator<<(ostream &out, const Base &rhs)
{
    cout << "Operator << overload: " << endl;
    out << rhs.x << " " << rhs.y << endl;
    return out;
}

Base::Base()
{
    x = 0;
    y=0;
}

Base::Base(int a, int b)
{
    x = a;
    y=b;
}

int Base::getX()
{
    return x;
}

int Base::getY()
{
    return y;
}

Base Base::operator=(const Base &rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

Base::Base(const Base&rhs)
{
    x = rhs.x;
    y=rhs.y;
}

Base::~Base()
{
    cout << "Destructor has been called" << endl;
}

void Base::display()
{
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

class Derived : public Base
{
    private:
        int w;
    public:
        Derived();
        Derived(int x, int y, int w);
        ~Derived();
        Derived(const Derived &rhs);
        Derived operator=(const Derived &rhs);
        void display();
};

Derived::Derived():Base()
{
    cout << "Derived constructor called" << endl;
    w = 0;
}

Derived::Derived(int x, int y, int c):Base(x, y)
{
    w = c;
}

Derived::~Derived()
{
    cout << "Destructor called for Derived" << endl;
}

Derived Derived::operator=(const Derived &rhs)
{
    Base::operator=(rhs);
    this->w = rhs.w;
    return *this;
}

Derived::Derived(const Derived &rhs): Base(rhs)
{
    cout << "Derived copy called" << endl;
    this->w = w;
}

void Derived::display()
{
    Base::display();
    cout << "Derived class : " << w << endl;
}

int main()
{
    Base b1;
    Base b2(20, 30);
    cout << "B1" << endl;
    b1.display();
    cout << "B2" << endl;
    b2.display();


    Base b3(b2);
    cout << "B3"<< endl;
    b3.display();

    Base b4;
    b4 = b3;
    cout << "B4" << endl;
    b4.display();

    cout << "Calling Derived functions" << endl;
    Derived d1;
    cout << "d1" << endl;
    d1.display();
    Derived d2(20,30,50);
    cout << "D2" << endl;
    d2.display();
    Derived d3(d2);
    cout << "D3 using copy constructor" << endl;
    d3.display();

    Derived d4;
    cout << "D4" << endl;
    d4=d3;
    d4.display();

    Base *b5;
    Derived d5(10,10,10);
    b5 = &d5;
    cout << "Redefining" << endl;
    b5->display();
}
