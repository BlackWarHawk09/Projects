#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:

    double re, im;

public:

    Complex()
    {
        re = im = 0.0;
    }

    Complex(const double& re)
    {
        this->re = re;
        this->im = 0.0;
    }

    Complex(const double& re, const double& im)
    {
        this->re = re;
        this->im = im;
    }

    Complex(const Complex &c)
    {
        this->re = c.re;
        this->im = c.im;
    }

    ~Complex() {};

    double real()
    {
        return re;
    }

    double imag()
    {
        return im;
    }

    double abs()
    {
        return sqrt(re * re + im * im);
    }

    Complex& operator = (const Complex& c)
    {
        this->re = c.re;
        this->im = c.im;
        return *this;
    }

    friend Complex& operator + (Complex(left), Complex(right))
    {
        static Complex tempAdd;
        tempAdd.re = left.re + right.re;
        tempAdd.im = left.im + right.im;
        return tempAdd;
    }

    friend Complex& operator - (Complex(left), Complex(right))
    {
        static Complex tempSub;
        tempSub.re = left.re - right.re;
        tempSub.im = left.im - right.im;
        return tempSub;
    }

    friend Complex& operator * (Complex(left), Complex(right))
    {
        static Complex tempMult;
        tempMult.re = left.re * right.re - left.im * right.im;
        tempMult.im = left.re * right.im + right.re *left.im;
        return tempMult;
    }

};

Complex I(0, 1);

void testComplex()
{
    Complex a, b, c;

    a = 1 - 2 * I;
    b = a * I;
    c = a * b * 17.7 + a * 3.14;

    if (abs(c.real() - 73.94) > 0.00001)
    {
        cout << "Error in counting real part of c = a*b*17.7 - a*3.14.\n"
                "Result must be 73.94 but result is " << c.real() << endl;
    }
    else
    {
        cout << "test 1 passed." << endl;
    }

    if (abs(c.imag() + 59.38) > 0.00001)
    {
        cout << "Error in counting imag part of c = a*b*17.7 - a*3.14.\n"
                "Result must be -59.38 but result is " << c.imag() << endl;
    }
    else
    {
        cout << "test 2 passed." << endl;
    }

    double lenght = c.abs();
    if (abs(lenght - 94.832) > 0.00001)
    {
        cout << "Error in counting c.abs()\n"
                "Result must be 94.832 but result is " << lenght << endl;
    }
    else
    {
        cout << "test 3 passed." << endl;
    }
}


int main()
{

    testComplex();

    cin.get();

    return 0;
}