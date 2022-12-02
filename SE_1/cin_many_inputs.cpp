#include <iostream>
#include <string>

using namespace std;

int main()
{
    int age;
    string name;

    cout << "Enter your name and age(exp: Amir 35): ";
    cin >> name >> age;

    cout << "Hi " << name << ", Are you really " << age << "?" << endl;
}