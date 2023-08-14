#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int imag;
    public:
        Complex();
        Complex(int x, int y);
        void setReal(int x);
        void SetImag(int y);
        void getReal();
        void getImag();
        void add(int x, int y);
        void Subtract(int x, int y);
        void print();
        void operator=(const Complex &rhs);
        Complex operator+(const Complex &rhs);
        Complex operator*(const Complex &rhs);
        Complex operator/(const Complex &rhs);
        Complex operator-(const Complex &rhs);
        friend ostream& operator<<(ostream& out, const Complex& rhs);
        Complex add1(const Complex& rhs);
};

Complex Complex::add1(const Complex& rhs)
{
    Complex t;
    t.real = real + rhs.real;
    t.imag = imag + rhs.imag;
    return t;
}
void Complex::setReal(int x)
{
    real = x;
}

void Complex::SetImag(int y)
{
    imag = y;
}

ostream& operator<<(ostream& out, const Complex& rhs)
{
    out << rhs.real << " + " << rhs.imag << "i" << endl;
    return out;
}

Complex Complex::operator-(const Complex &rhs)
{
    Complex m;
    m.real = real-rhs.real;
    m.imag = imag-rhs.imag;
    return m;
}

Complex Complex:: operator/(const Complex &rhs)
{
    Complex m;
    m.real = real/rhs.real;
    m.imag = imag/rhs.imag;
    return m;
}
Complex Complex::operator*(const Complex&rhs)
{
    Complex m;
    m.real = real*rhs.real;
    m.imag = imag*rhs.imag;
    return m;
}
Complex Complex::operator+(const Complex &rhs)
{
    Complex n;
    n.real = real - rhs.real;
    n.imag = imag - rhs.imag;
    return n;
}

Complex::Complex()
{
    real = 0;
    imag = 0;
}
Complex::Complex(int x, int y)
{
    real = x;
    imag = y;
}

void Complex::print()
{
    cout << "Complex Number: " << real << " + i" << imag << endl; 
}

void Complex::operator=(const Complex &rhs)
{
    real = rhs.real;
    imag = rhs.imag;
}

int main()
{
    Complex c1(25, 67);
    Complex c2(13, 17);
    Complex c3(12, 4);
    Complex c4;
    c4 = c4.add1(c2);
    cout << c4 << endl;
};