#include <iostream>
using namespace std;

class Rational
{
    private:
        int numerator;
        int denominator;
    public:
        Rational();
        Rational(int x, int y);
        void setNumerator(int num);
        void setDenominator(int den);
        int getNumerator();
        int getDenominator();
        friend ostream& operator<<(ostream& out, const Rational &rhs);
};

void Rational::setNumerator(int x)
{
    numerator = x;
}

void Rational::setDenominator(int y)
{
    denominator = y;
}

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int x, int y)
{
    numerator = x;
    denominator = y;
    if (denominator == 0)
    {
        cout << "Invalid Input" << endl;
        exit(-1);
    }
}

ostream& operator<<(ostream& out, const Rational &rhs)
{
    out << rhs.numerator << "/" << rhs.denominator << endl;
}

int main()
{
    Rational c1(2,1);
    cout << c1;
    Rational c2;
    c2.setNumerator(2);
    c2.setDenominator(4);
    cout << c2;
}