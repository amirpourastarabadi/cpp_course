#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(double real, double i)
    {
        this->real = real;
        this->i = i;
    }
    double real;
    double i;
};

ostream &operator<<(ostream &out, Complex c)
{
    out << '(' << to_string(c.real) << ", " << (c.real > 0 ? "+" : "") << c.i << "i)" << endl;
    return out;
}

int main()
{
    Complex c(3, 5);
    cout << c;
    return 0;
}