#include<iostream>
#include<string>

using namespace std;

template<typename T>
void print_array(T a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    string s[] = {"John", "Doe", "Amir", "porastarabadi"};

    print_array(a, 5);
    cout << endl;
    print_array(s, 4);
    cout << endl;
    return 0;
}

