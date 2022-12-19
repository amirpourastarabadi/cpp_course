#include <iostream>

#include "Animal.cpp"
#include "Bird.cpp"
#include "Reptile.cpp"

using namespace std;

int main()
{
    Bird b;
    Reptile r;

    cout << "Bird: " << b.move() << "\nReptile: " << r.move() << endl;
}