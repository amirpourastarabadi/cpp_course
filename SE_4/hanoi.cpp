#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> shaft;

// i have 3 shaft
// all disks are on one(from)
// i want to move them to a specific shaft(to)
// i can use third one (spare)
// always smaller disc must be on bigger one

shaft from;
shaft to;
shaft spare;

void setup(int number_of_discs)
{
    for (int i = number_of_discs; i >= 1; i--)
    {
        from.push_back(i);
    }
}

void print(shaft shaft, string name)
{
    int space = 5 - name.length();

    for (int i = 0; i < space; i++)
    {
        cout << " ";
    }
    cout << name << " |";
    for (int i = 0; i < shaft.size(); i++)
    {
        cout << shaft[i] << " ";
    }
    cout << endl;
}

void report()
{
    print(from, "from");
    print(to, "to");
    print(spare, "spare");
}

void move(shaft &from, shaft &to)
{
    to.push_back(from.back());
    from.pop_back();
}

void hanoi(shaft &from, shaft &to, shaft &spare, int number_of_disc)
{
    if (number_of_disc == 1)
    {
        move(from, to);
        return;
    }
    hanoi(from, spare, to, number_of_disc - 1);
    move(from, to);
    hanoi(spare, to, from, number_of_disc - 1);
}

int get_number_of_discs()
{
    int number_of_discs;

    cout << "Enter number of discs: ";
    
    cin >> number_of_discs;

    return number_of_discs;
}

int main()
{
    int number_of_discs = get_number_of_discs(); 

    setup(number_of_discs);

    report();

    hanoi(from, to, spare, number_of_discs);

    report();
}