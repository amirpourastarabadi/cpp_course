#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node
{
public:
    Node(T data);
    T data;
};

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
}

template <typename T>
ostream &operator<<(ostream &out, Node<T> node)
{
    out << node.data;
    return out;
}

int main()

{

    Node<int> i(10);
    cout << i << endl;

    Node<string> s("Hello template\n");
    cout << s;
    return 0;
}