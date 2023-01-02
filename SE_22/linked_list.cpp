#include <iostream>

using namespace std;

class Node
{
public:
    Node(int data, Node *next, Node *prev);
    void set_next(Node *next) { this->next = next; }
    void set_prev(Node *prev) { this->prev = prev; }
    Node *get_next() { return this->next; }
    Node *get_prev() { return this->prev; }
    int get_data() { return this->data; }

private:
    int data;
    Node *next;
    Node *prev;
};

Node::Node(int data, Node *next = NULL, Node *prev = NULL)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

class LinkedList
{
public:
    LinkedList();
    void append(int data);
    void pop();
    void insert(int index, int value);
    // void remove(int index);
    void print();
    int get_size() { return this->size; };

private:
    Node *head;
    Node *tail;
    int size = 0;
};

LinkedList::LinkedList()
{
    this->head = new Node(-1);
    this->tail = new Node(-1);
    this->head->set_next(this->tail);
    this->tail->set_prev(this->head);
}
void LinkedList::append(int data)
{
    this->size += 1;
    Node *new_node = new Node(data);
    Node *lastNode = this->tail->get_prev();
    lastNode->set_next(new_node);
    new_node->set_prev(lastNode);
    new_node->set_next(this->tail);
    this->tail->set_prev(new_node);
}
void LinkedList::pop()
{
    this->size -= 1;
    this->tail->set_prev(this->tail->get_prev()->get_prev());
    this->tail->get_prev()->set_next(this->tail);
}
void LinkedList::print()
{
    if (this->size == 0)
    {
        cout << "Empty list\n";
        return;
    }
    Node *current = this->head->get_next();
    for (int i = 0; i < this->get_size(); i++)
    {
        cout << current->get_data() << ' ';
        current = current->get_next();
    }
    cout << endl;
}

void LinkedList::insert(int index, int value)
{
    if(index >= size)
    {
        cout << "List contains only " << size << " elemets\n";
        return;
    }

    Node *targetNode = head;
    for(int i = 0 ; i < index; i++)
    {
        targetNode = targetNode->get_next();
    }

    Node *new_node = new Node(value);
    targetNode->get_next()->set_prev(new_node);
    new_node->set_next(targetNode->get_next());
    new_node->set_prev(targetNode);
    targetNode->set_next(new_node);
    size += 1;
}

main()
{
    LinkedList l;
    l.print();

    cout << "append some items:\n";
    for (int i = 1; i <= 1024; i *= 2)
        l.append(i);
    l.print();

    cout << "pop 3 items:\n";
    for (int i = 0; i < 3; i++)
    {
        l.pop();
    }
    l.print();

    for (int i = 1; i <= 1024; i *= 2)
        l.append(i);
    cout << "append more items:\n";
    l.print();
    
    cout << "pop 3 more items:\n";
    for (int i = 0; i < 3; i++)
    {
        l.pop();
    }
    l.print();

    cout << "insert 44 at index 0:\n";
    l.insert(0, 44);
    l.print();


    cout << "insert 66 at index 3:\n";
    l.insert(3, 66);
    l.print();

    return 0;
}