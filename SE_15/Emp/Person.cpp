#include <string>

using namespace std;

class Person
{
public:
    Person(){};
    Person(string name) { this->name = name; }
    string get_name() { return name; }

protected:
    string name = "UN KNOWN";
};