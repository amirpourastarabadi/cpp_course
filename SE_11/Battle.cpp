#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Counter
{
public:
    Counter(string name)
    {
        this->name = name;
        counters_num += 1;
    }
    static int get_count()
    {
        return counters_num;
    }

private:
    string name;
    int kills = 0;
    int dies = 0;
    static int counters_num;
};

class Terror
{
public:
    Terror(string name)
    {
        this->name = name;
        terror_num += 1;
    }

    static int get_count()
    {
        return terror_num;
    }

private:
    string name;
    int kills = 0;
    int dies = 0;
    static int terror_num;
};

int Counter::counters_num = 0;
int Terror::terror_num = 0;

int main()
{
    Counter c1 = Counter("amir");     
    Counter c2 = Counter("ali");
    Counter c3 = Counter("marzieh");

    Terror t1 = Terror("saman");     
    Terror t2 = Terror("sali");

    cout << "number of counters = " << Counter::get_count() << endl;     
    cout << "number of terrors = " << Terror::get_count() << endl;     

    return 0;
}