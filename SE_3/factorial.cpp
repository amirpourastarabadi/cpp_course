#include <iostream>

using namespace std;

int recursion_fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * recursion_fact(n - 1);
}

int fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Simple: " << fact(n) << endl;

    cout << "Recursion : " << recursion_fact(n) << endl;
    
    return 0;
}