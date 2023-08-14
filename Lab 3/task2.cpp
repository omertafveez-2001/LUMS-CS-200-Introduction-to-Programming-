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
        Rational operator=(const Rational& rhs);
        bool operator>=(const Rational& rhs);
        bool operator<=(const Rational&rhs);
        bool operator>(const Rational &rhs);
        bool operator<(const Rational &rhs);
};

bool Rational::operator>(const Rational&rhs)
{
    Rational t;
    if (t.numerator*rhs.denominator > rhs.numerator*t.denominator)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

bool Rational::operator<(const Rational&rhs)
{
    Rational t;
    if (t.numerator*rhs.denominator < rhs.numerator*t.denominator)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
bool Rational::operator<=(const Rational&rhs)
{
    Rational t;
    if (t.numerator*rhs.denominator == rhs.numerator*t.denominator)
    {
        return 0;
    }
    else if (t.numerator*rhs.denominator < rhs.numerator*t.denominator)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
bool Rational::operator>=(const Rational&rhs)
{
    Rational t;
    if (t.numerator*rhs.denominator == rhs.numerator*t.denominator)
    {
        return 0;
    }
    else if (t.numerator*rhs.denominator > rhs.numerator*t.denominator)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
Rational Rational::operator=(const Rational& rhs)
{
    Rational t;
    t.numerator = rhs.numerator;
    t.denominator = rhs.denominator;
    return t;
}

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
    Rational c1(1,2);
    Rational c2(-4,2);
    if (c2>=c2)
    {
        cout << "True" << endl;
    }
    Rational c3;
    cout << c3 << endl;
}