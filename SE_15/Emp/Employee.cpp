#include <iostream>
#include "Person.cpp"

using namespace std;



class Employee : public Person
{
public:
    Employee(string code);
    Employee(string name, string code);
    string get_code() { return this->code; }

private:
    string code;
};

Employee::Employee(string code)
{
    this->code = code;
}
Employee::Employee(string name, string code)
    : Person(name)
{
    this->code = code;
}

ostream &operator<<(ostream &out, Employee emp)
{
    out << "Emp:\n\tName: "
        << emp.get_name()
        << "\n\tCode: "
        << emp.get_code()
        << endl;

    return out;
}
