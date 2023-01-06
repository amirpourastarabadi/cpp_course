#include <iostream>
#include <string>

using namespace std;

template <typename T, typename V>
class Pair
{
public:
    Pair(T t, V v) : first(t), second(v) {}
    T get_first() { return first; }
    V get_second() { return second; }

private:
    T first;
    V second;
};

template <typename T, typename V>
ostream &operator<<(ostream &out, Pair<T, V> pair)
{
    out << '(' << pair.get_first() << ", " << pair.get_second() << ")\n";
    return out;
}

int main()
{
    Pair<int, float> p1(3, 3.1415);
    cout << p1;

    Pair<int, string> p2(7, "Heloo template");
    cout << p2;
}