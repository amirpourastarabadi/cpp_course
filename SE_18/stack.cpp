#include <iostream>
#include <string>
using namespace std;

class invalid_stack_method_call
{
};

class Stack
{
private:
    int size;
    int count;
    int *container;

public:
    Stack(int size);
    ~Stack();
    Stack(const Stack &stack);
    Stack &operator=(const Stack &);

    int get_top()
    {
        if (count > 0)
        {
            return container[count - 1];
        }
        throw invalid_stack_method_call();
    }

    int pop()
    {
        if (count < 0)
        {
            throw invalid_stack_method_call();
        }
        count -= 1;
        return container[count];
    }

    void push(int value)
    {
        if (count > size)
        {
            throw invalid_stack_method_call();
        }

        container[count] = value;
        count += 1;
    }

    int get_count()
    {
        return count;
    }

    void insert(int index, int value)
    {
        if (index >= count)
        {
            throw invalid_stack_method_call();
        }
        container[index] = value;
    }
};

Stack::Stack(int size = 10)
{
    cout << "Cunstractor calling\n";
    container = new int[size];
    this->size = size;
    this->count = 0;
}

Stack::~Stack()
{
    cout << "Destractor calling\n";
    delete[] container;
}

Stack::Stack(const Stack &stack)
{
    cout << "Deep Copy Calling\n";
    this->count = stack.count;
    this->size = stack.size;
    this->container = new int[this->size];
    for (int i = 0; i < this->get_count(); i++)
        this->container[i] = stack.container[i];
}

void print_stack(Stack s)
{
    while (s.get_count() > 0)
    {
        cout << s.get_top() << " ";
        s.pop();
    }
    cout << endl;
}

void magic_method(Stack s)
{
    while (s.get_count() > 0)
    {
        s.insert(s.get_count() - 1, s.get_top() * 10);
        s.pop();
    }
}

Stack &Stack::operator=(const Stack &stack)
{
    if (this == &stack)
        return *this;
    this->count = stack.count;
    this->size = stack.size;
    this->container = new int[this->size];
    for (int i = 0; i < this->get_count(); i++)
        this->container[i] = stack.container[i];

    return *this;
}

int main()
{
    Stack s;
    Stack s2;
    s2 = s;
    s2.push(3333);
    s.push(10);
    s.push(20);
    s.push(30);
    magic_method(s);

    print_stack(s2);
    print_stack(s);

    return 0;
}
