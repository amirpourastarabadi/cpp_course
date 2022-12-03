#include <iostream>

using namespace std;

int recursion_fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return recursion_fib(n - 1) + recursion_fib(n - 2);
}

int fib(int n)
{
    int a = 1;
    int b = 1;
    int c = a + b;

    if(n == 1 || n == 2)
    {
        return 1;
    }

    for(int i = 3; i < n; i++)
    {
        a = b;
        b = c;
        c = a + b;
    }

    return c;
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Simple: " << fib(n) << endl;

    cout << "Recursion : " << recursion_fib(n) << endl;

    return 0;
}