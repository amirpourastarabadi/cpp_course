#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }
    Complex operator+(const Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex &operator+=(const Complex &c)
    {
        real += c.real;
        imag += c.real;
    }
    void print()
    {
        cout << "(" << to_string(real) << ", " << ((imag > 0) ? "+" : "") << to_string(imag) << ")" << endl;
    }
};

int main()
{
    Complex a(1, 1);
    Complex b(2, 2);
    Complex c = a + b;
    c.print();
    a.print();
    a += c;
    a.print();   
}