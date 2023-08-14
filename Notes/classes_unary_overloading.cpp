/*
OVERLOADING BITWISE UNARY OPERATORS (+,-,*)
type cannot be changed. Unary stays unary.
predence order cannot be changed.

All overloaded operators are inherited except =.
*/

#include <iostream>
using namespace std;

class CarLeasing
{
    private:
        int car_price;
        int car_loan;
        int loan_month;
    public:
        CarLeasing();

        //parameterized constructors.
        CarLeasing(int c, int l, int m); 

        //copy constructor & assignment operator
        CarLeasing(const CarLeasing &rhs);
        void operator=(const CarLeasing &rhs);

        //adding 2 objects overloading
        CarLeasing operator+(const CarLeasing &rhs);
        CarLeasing operator-(const CarLeasing &rhs);
        CarLeasing operator+(const int c);
        friend CarLeasing operator+(const int c, const CarLeasing &rhs);

        //setters
        void setPrice(int a);
        void setLoan(int b);
        void setLoanMonth(int m);

        //getters
        int getPrice();
        int getLoan();
        int getLoanMonth();

        //displaying
        void displayLog();

        //<< overload
        friend ostream& operator<<(ostream& out, const CarLeasing &rhs);
};

CarLeasing::CarLeasing()
{
    car_price=0;
    car_loan=0;
    loan_month=0;
}

CarLeasing::CarLeasing(int a, int b, int c)
{
    car_price = a;
    car_loan=b;
    loan_month=c;
}

void CarLeasing::setPrice(int a)
{
    car_price =a;
}
void CarLeasing::setLoan(int b)
{
    car_loan=b;
}
void CarLeasing::setLoanMonth(int m)
{
    loan_month=m;
}

int CarLeasing::getPrice()
{
    return car_price;
}
int CarLeasing::getLoan()
{
    return car_loan;
}
int CarLeasing::getLoanMonth()
{
    return loan_month;
}
void CarLeasing::displayLog()
{
    cout << "Car's Price: " << car_price << endl;
    cout << "Car's Loan: " << car_loan << endl;
    cout << "Loan Months: " << loan_month << endl;
}

CarLeasing::CarLeasing(const CarLeasing &rhs)
{
    car_price=rhs.car_price;
    car_loan=rhs.car_loan;
    loan_month=rhs.loan_month;
}

void CarLeasing::operator=(const CarLeasing &rhs)
{
    car_price=rhs.car_price;
    car_loan=rhs.car_loan;
    loan_month = rhs.loan_month;
}

//+ overloaded
CarLeasing CarLeasing::operator+(const CarLeasing &rhs)
{
    CarLeasing t;
    t.car_price = car_price + rhs.car_price;
    t.car_loan = car_loan + rhs.car_loan;
    t.loan_month = loan_month + rhs.loan_month;
    return t;
}

//- overloaded
CarLeasing CarLeasing::operator-(const CarLeasing &rhs)
{
    CarLeasing t;
    t.car_price = car_price - rhs.car_price;
    t.car_loan = car_loan - rhs.car_loan;
    t.loan_month = loan_month - rhs.loan_month;
    return t;
}

ostream& operator<<(ostream& out, const CarLeasing &rhs)
{
    out << "Car's Price: " << rhs.car_price << endl;
    out << "Car's Loan: " << rhs.car_loan << endl;
    out << "Loan Months: " << rhs.loan_month << endl;
    return out;
}

//carleasing + const
CarLeasing CarLeasing::operator+(const int c)
{
    CarLeasing t;
    t.car_price = c+car_price;
    t.car_loan = car_loan;
    t.loan_month = loan_month;
    return t;
}

CarLeasing operator+(const int c, const CarLeasing &rhs)
{
    CarLeasing t;
    t.car_price = c+rhs.car_price;
    t.car_loan = rhs.car_loan;
    t.loan_month = rhs.loan_month;
    return t;
}

int main()
{
    CarLeasing c1(12000,3000,3);
    CarLeasing c2(c1);
    cout << "Copy Constructor: " << endl;
    cout << c2 << endl;
    CarLeasing c3;
    c3=c2;
    cout << "Assignment Operator: " << endl;
    cout << c3 << endl;
    c3=c1+c2;
    cout << "+ overloaded: " << endl;
    cout << c3 << endl;
    CarLeasing c4;
    c4 = c3+c2;
    cout << "CarLeasing + const" << endl;
    cout << c4 << endl;
    CarLeasing c5;
    c5=1000+c4;
    cout << "Const + CarLeasing: " << endl;
    cout << c5 << endl;
}

