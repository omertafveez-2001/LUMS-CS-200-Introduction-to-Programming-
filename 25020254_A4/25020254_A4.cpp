#include <iostream>
using namespace std;

struct PolyTerm
{
    int coefficient;
    int power;
};

class Polynomial
{
    private:
        PolyTerm *terms;
        int size;
    public:
        Polynomial();
        Polynomial(int*arr1, int si);
        Polynomial(int*arr1, int*arr2, int size);
        Polynomial(const Polynomial &rhs);
        virtual ~Polynomial();
        Polynomial operator+(const Polynomial &rhs)const;
        friend ostream& operator<<(ostream& out, const Polynomial &rhs);
        Polynomial derivative()const;

        //setters
        void setSize(int s);

        //getters
        int getSize();
        PolyTerm getTerms();
};

void Polynomial::setSize(int s)
{
    size = s;
}

PolyTerm Polynomial::getTerms()
{
    return *terms;
}

int Polynomial::getSize()
{
    return size;
}

Polynomial::Polynomial()
{
    terms = nullptr;
    size = 0;
}

Polynomial::Polynomial(int* arr, int si)
{
    size = si;
    terms = new PolyTerm[size];
    for(int i = 0; i<size; i++)
    {
        terms[i].coefficient = arr[i];
        terms[i].power = size-i-1;
    }
}

Polynomial::Polynomial(int *arr, int *arr2, int si)
{
    size = si;
    terms = new PolyTerm[size];
    for(int i = 0; i<size; i++)
    {
        terms[i].coefficient = arr[i];
        terms[i].power = arr2[i];
    }
}

Polynomial::Polynomial(const Polynomial &rhs)
{
    size = rhs.size;
    terms = new PolyTerm[size];
    for(int i = 0; i<size;i++)
    {
        terms[i].coefficient = rhs.terms[i].coefficient;
        terms[i].power = rhs.terms[i].power;
    }
}

Polynomial::~Polynomial()
{
    delete [] terms;
}

ostream& operator<<(ostream& out, const Polynomial &rhs)
{
    for(int i = 0; i<rhs.size; i++)
    {
        if(i==rhs.size-1)
        {
            out << rhs.terms[i].coefficient; 
        }
        else
        {
            out << rhs.terms[i].coefficient << "x^" << rhs.terms[i].power << " + ";
        }
    }
    out << endl;
    return out;
}

Polynomial Polynomial::operator+(const Polynomial &rhs)const
{
    if(size>=rhs.size)
    {
        int difference = size - rhs.size;
        int newsize = size;
        int* c = new int [newsize];
        int *p = new int [newsize];

        for(int i = 0; i<newsize;i++)
        {
            c[i] = terms[i].coefficient;
            p[i] = terms[i].power;
        }
        for(int i = 0;i<rhs.size;i++)
        {
            c[difference+i] = c[difference+i] + rhs.terms[i].coefficient;
        }

        Polynomial sum(c, p, newsize);
        return sum;
    }
    else if(size<=rhs.size)
    {
        int difference = rhs.size - size;
        int newsize = rhs.size;
        int* c = new int [newsize];
        int *p = new int [newsize];

        for(int i = 0; i<newsize;i++)
        {
            c[i] = terms[i].coefficient;
            p[i] = terms[i].power;
        }
        for(int i = 0;i<size;i++)
        {
            c[difference+i] = c[difference+i] + rhs.terms[i].coefficient;
        }

        Polynomial sum(c, p, newsize);
        return sum;
    }
}

Polynomial Polynomial::derivative() const
{
    Polynomial result;
    result.size = size - 1;
    result.terms = new PolyTerm[size - 1];
    for (int i = 0; i < size - 1; i++) {
        result.terms[i].coefficient = terms[i].coefficient * terms[i].power;
        result.terms[i].power = size - i - 2;
    }
    return result;
}

class LinearPolynomial: public Polynomial
{
    private:
        int a;
        int b;
    public:
        LinearPolynomial();
        LinearPolynomial(int a, int b, int*arr1, int*arr2, int size);
        LinearPolynomial(const LinearPolynomial &rhs);
        ~LinearPolynomial();
};

LinearPolynomial::~LinearPolynomial()
{
    a = 0;
    b = 0;
}

LinearPolynomial::LinearPolynomial():Polynomial()
{
    a = 0;
    b = 0;
}

LinearPolynomial::LinearPolynomial(int x, int y, int*arr1, int*arr2, int si):Polynomial(arr1, arr2, si)
{
    a = x;
    b = y;
}

LinearPolynomial::LinearPolynomial(const LinearPolynomial &rhs):Polynomial(rhs)
{
    a = rhs.a;
    b = rhs.b;
}

class QuadraticPolynomial: public Polynomial
{
    private:
        int a;
        int b;
        int c;
    public:
        QuadraticPolynomial();
        QuadraticPolynomial(int a, int b, int c, int*arr1, int*arr2, int size);
        QuadraticPolynomial(const QuadraticPolynomial &rhs);
        ~QuadraticPolynomial();
};

QuadraticPolynomial::QuadraticPolynomial():Polynomial()
{
    a = 0;
    b = 0;
    c = 0;
}

QuadraticPolynomial::QuadraticPolynomial(int x, int y, int z, int*arr1, int*arr2, int si):Polynomial(arr1, arr2, si)
{
    a = x;
    b = y;
    c = z;
}
QuadraticPolynomial::QuadraticPolynomial(const QuadraticPolynomial &rhs):Polynomial(rhs)
{
    a = rhs.a;
    b = rhs.b;
    c = rhs.c;
}

QuadraticPolynomial::~QuadraticPolynomial()
{
    a=0;
    b=0;
    c=0;
}

class CubicPolynomial:public Polynomial
{
    private:
        int a;
        int b;
        int c;
        int d;
    public:
        CubicPolynomial();
        CubicPolynomial(int a, int b, int c, int d, int* arr1, int *arr2, int si);
        CubicPolynomial(const CubicPolynomial &rhs);
        ~CubicPolynomial();
};

CubicPolynomial::CubicPolynomial():Polynomial()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

CubicPolynomial::CubicPolynomial(int x, int y, int z, int w, int*arr1, int*arr2, int si):Polynomial(arr1, arr2, si)
{
    a = x;
    b = y;
    c = z;
    d = w;
}

CubicPolynomial::CubicPolynomial(const CubicPolynomial &rhs):Polynomial(rhs)
{
    a = rhs.a;
    b = rhs.b;
    c = rhs.c;
    d = rhs.d;
}

CubicPolynomial::~CubicPolynomial()
{
    cout << "Destructor is called" << endl;
}

Polynomial addPolynomials(Polynomial &object1, Polynomial&object2)
{
    return object1 + object2;
}

//could not make user menu because of memory management and memory segmentation. Could not find a workaround.
int main()
{
    //linear polynomial
    cout << "Constructing Linear Polynomial" << endl;
    int size_linear = 2;
    int *arr_co_linear = new int [size_linear];
    int *arr_po_linear = new int [size_linear];
    for(int i = 0; i<size_linear;i++)
    {
        cout << "Enter element " << i << ": ";
        cin >>arr_co_linear[i];
        arr_po_linear[i] = size_linear-i-1;
    }
    LinearPolynomial lp(arr_co_linear[1], arr_co_linear[0], arr_co_linear, arr_po_linear, size_linear);
    cout << "Your Linear Polynomial: " << lp << endl;

    //quadratic polynomial
    cout << "Constructing Quadratic Polynomial" << endl;
    int size_quad = 3;
    int *arr_co_quad = new int [size_quad];
    int *arr_po_quad = new int [size_quad];
    for(int i = 0; i<size_quad;i++)
    {
        cout << "Enter element " << i << ": ";
        cin >>arr_co_quad[i];
        arr_po_quad[i] = size_quad-i-1;
    }
    QuadraticPolynomial qp(arr_co_quad[2],arr_co_quad[1], arr_co_quad[0], arr_co_quad, arr_po_quad, size_quad);
    cout << "Your Quadratic Polynomial: " << qp << endl;

    //cubic polynomial
    cout << "Constructing Cubic Polynomial" << endl;
     int size_cubic = 4;
    int *arr_co_cubic = new int [size_cubic];
    int *arr_po_cubic = new int [size_cubic];
    for(int i = 0; i<size_cubic;i++)
    {
        cout << "Enter element " << i << ": ";
        cin >>arr_co_cubic[i];
        arr_po_cubic[i] = size_cubic-i-1;
    }
    CubicPolynomial cp(arr_co_cubic[3],arr_co_cubic[2],arr_co_cubic[1], arr_co_cubic[0], arr_co_cubic, arr_po_cubic, size_cubic);
    cout << "Your Cubic Polynomial: " << cp << endl;

    //calculating derivates
    cout << "Calculating Derivates...." << endl;
    Polynomial temp(lp);
    Polynomial derived_linear(temp.derivative());
    cout << "Derivatives of Linear Polynomial: " << derived_linear << endl;
    Polynomial temp1(qp);
    Polynomial derived_quad(temp1.derivative());
    cout << "Derivatives of Quadratic Polynomial: " << derived_quad << endl;
    Polynomial temp2(cp);
    Polynomial derived_cubic(temp2.derivative());
    cout << "Derivates of Cubic Polynomial: " << derived_cubic << endl;

    //sum
    cout << "Addition of linear Polynomial and Derivative of Linear Polynomial" << endl;
    cout << addPolynomials(temp, derived_linear) << endl;
    cout << "Addition of Quadratic Polynomial and Derivative of Quadratic Polynomial" << endl;
    cout << addPolynomials(temp1, derived_quad) << endl;
    cout << "Addition of Cubic Polynomial and Derivative of Cubic Polynomial" << endl;
    cout << addPolynomials(temp2, derived_cubic);
    cout << "Addition of Cubic with Cubic" << endl;
    cout << addPolynomials(temp2, temp2);
    cout << "Addition of Linear with Cubic" << endl;
    cout << addPolynomials(temp2, temp);
}