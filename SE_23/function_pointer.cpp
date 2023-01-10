#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Student
{
public:
    Student(string _name, int _number) : name(_name), number(_number) {}

    string name;
    int number;
};
typedef void (*sort_student)(vector<Student> &students);

void sort_by_name(vector<Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students.size() - 1; j++)
        {
            if (students[j].name > students[j + 1].name)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sort_by_number(vector<Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students.size() - 1; j++)
        {
            if (students[j].number > students[j + 1].number)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sort_students(vector<Student> students, sort_student fn)
{
    fn(students);
}

int main()
{
    vector<Student> s;
    s.push_back(Student("Kaveh", 12));
    s.push_back(Student("Ferdos", 14));
    s.push_back(Student("Amir", 10));

    cout << "main order: \n";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i].name << " -> " << s[i].number << endl;
    }
    cout << endl;

    map<char, sort_student> func_map;
    func_map['1'] = sort_by_name;
    func_map['2'] = sort_by_number;

    char inp;
    cout << "select sort function:(1 or 2)\n\t1- sort by name\n\t2- sort by number\n";
    cin >> inp;

    func_map[inp](s);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i].name << " -> " << s[i].number << endl;
    }
    cout << endl;

    return 0;
}