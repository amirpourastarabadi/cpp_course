#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual void make_noise() = 0;
};

class Vet
{
public:
    void inject(Animal *animal)
    {
        // inject
        animal->make_noise();
    }
};

class Cat : public Animal
{
public:
    virtual void make_noise()
    {
        cout << "Miowwwww" << endl;
    }
};

class Dog : public Animal
{
public:
    virtual void make_noise()
    {
        cout << "OWWWWWWWWWWW" << endl;
    }
};

void print_menu()
{
    cout << "select animal:\n\t"
         << "1. Cat\n\t"
         << "2. Dog\n\t"
         << "3. quit\n\t"
         << endl;
}

vector<Animal *> read_animal()
{
    int input;
    vector<Animal *> animals;
    print_menu();

    while (cin >> input)
    {
        if (input == 3)
        {
            break;
        }
        if (input != 1 && input != 2)
        {
            cout << "Wrong input!!\n";
            print_menu();
            continue;
        }

        if (input == 1)
        {
            animals.push_back(new Cat);
        }
        else if (input == 2)
        {
            animals.push_back(new Dog);
        }
        print_menu();
    }

    return animals;
}

int main()
{
    Vet v;
    vector<Animal *> animals = read_animal();
    for(int i = 0; i < animals.size() ; i ++)
    {
        v.inject(animals[i]);
    }
    return 0;
}