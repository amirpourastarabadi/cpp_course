#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX_HEALTH = 10;
const int LEFT = 0;
const int RIGHT = 1;

class BattleField;

class Fighter
{
public:
    Fighter(char name, int location, BattleField *field, int health = MAX_HEALTH)
    {
        this->name = name;
        this->location = location;
        this->health = health;
        this->field = field;
    }

    int get_health()
    {
        return health;
    }
    string get_name()
    {
        return name;
    }
    bool is_alive()
    {
        return !is_dead;
    }

    void play_a_round()
    {
        int new_location = this->get_new_location();

        if (this->field->is_empty(new_location))
        {
            this->move(new_location);
        }

        this->fight_with(this->field->get_fighter(new_location));
    }

    void move(int location)
    {
        cout << this << " move from " << this->location << " to " << location << endl;
        this->field->update_location(this->location, location);
        this->location = location;
    }

    void fight_with(Fighter *opponent)
    {
        cout << this << " VS " << opponent << endl;
    }

private:
    string name;
    int health;
    int location;
    bool is_dead = false;
    BattleField *field;

    int get_new_location()
    {
        int direction = rand() % 2;
        if (direction == LEFT && this->location > 0)
        {
            return this->location - 1;
        }

        if (direction == RIGHT && this->location < this->field->size())
        {
            return this->location + 1;
        }
    }
};

class BattleField
{
public:
    BattleField(int battle_size, int fighter_num)
    {
        battle_container = vector<Fighter *>(battle_size, NULL);

        for (int i = 0; i < fighter_num; i++)
        {
            int location = find_an_empty_location();
            Fighter *f = new Fighter('a' + i, location, this);
            set_fighter_in_battle(f, location);
        }
    }

    void start_fight()
    {
        for (int i = 0; i < fighter_container.size(); i++)
        {
            if (fighter_container[i]->is_alive())
                fighter_container[i]->play_a_round();
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

    bool is_empty(int location)
    {
        return battle_container[location] == 0;
    }
    void update_location(int old_location, int new_location)
    {
        this->battle_container[new_location] = this->battle_container[old_location];
        this->battle_container[old_location] = 0;
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
        while (true)
        {
            int location = rand() % battle_zise;
            if (this->is_empty(location))
                return location;
        }
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
    srand(time(0));

    BattleField b(20, 5);
    cout << b;
    b.start_fight();

    return 0;
}