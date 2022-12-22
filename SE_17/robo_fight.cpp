#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX_HEALTH = 10;

class Fighter
{
public:
    Fighter(char name, int location, int health = MAX_HEALTH)
    {
        this->name = name;
        this->location = location;
        this->health = health;
    }

    int get_health()
    {
        return health;
    }
    string get_name()
    {
        return name;
    }

private:
    string name;
    int health;
    int location;
};

class BattleField
{
public:
    BattleField(int battle_size, int fighter_num)
    {
        fighter_container = vector<Fighter *>(fighter_num, NULL);
        battle_container = vector<Fighter *>(battle_size, NULL);

        for (int i = 0; i < fighter_num; i++)
        {
            int location = find_an_empty_location();
            Fighter *f = new Fighter('a' + i, location);
            set_fighter_in_battle(f, location);
        }
    }

    int size()
    {
        return battle_container.size();
    }
    Fighter *get_fighter(int index)
    {
        return battle_container[index];
    }

private:
    void set_fighter_in_battle(Fighter *f, int location)
    {
        battle_container[location] = f;
        fighter_container.push_back(f);
    }
    int find_an_empty_location()
    {
        int battle_zise = battle_container.size();
        int location = rand() % battle_zise;
        while (battle_container[location] != NULL)
        {
            int location = rand() % battle_zise;
        }

        return location;
    }
    vector<Fighter *> fighter_container;
    vector<Fighter *> battle_container;
};

ostream &operator<<(ostream &out, Fighter f)
{
    out << f.get_name() << to_string(f.get_health());
    return out;
};

ostream &operator<<(ostream &out, BattleField b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b.get_fighter(i) == NULL)
        {
            out << "__";
        }
        else
        {
            out << *(b.get_fighter(i));
        }
        out << ' ';
    }
    out << endl;

    return out;
}

int main()
{
    BattleField b(10, 2);
    cout << b;
    // b.start_fight();

    return 0;
}