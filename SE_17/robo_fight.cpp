#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX_HEALTH = 10;
const int MY_TURN = 0;
const int HIS_TURN = 0;
const int LEFT = 0;
const int RIGHT = 1;

class Fighter;
class BattleField;

class Fighter
{
public:
    Fighter(char name, int location, BattleField *field, int health);
    int get_health();
    string get_name();
    bool is_alive();
    void play_a_round();
    void move(int location);
    void fight_with(Fighter *opponent);
    void get_tired(Fighter *fighter);

private:
    string name;
    int health;
    int location;
    bool is_dead = false;
    BattleField *field;
    int get_new_location();
};
class BattleField
{
public:
    BattleField(int battle_size, int fighter_num);
    void start_fight();
    int size();
    bool is_empty(int location);
    void update_location(int old_location, int new_location);
    Fighter *get_fighter(int index);
    bool winner_doesnot_selected();
    bool out_of_field(int location);
    void print_winner();

private:
    void set_fighter_in_battle(Fighter *f, int location);
    int find_an_empty_location();
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
        if (b.get_fighter(i) == NULL || !b.get_fighter(i)->is_alive())
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

Fighter::Fighter(char name, int location, BattleField *field, int health = MAX_HEALTH)
{
    this->name = name;
    this->location = location;
    this->health = health;
    this->field = field;
}

int Fighter::get_health()
{
    return health;
}
string Fighter::get_name()
{
    return name;
}
bool Fighter::is_alive()
{
    return !is_dead;
}
void Fighter::play_a_round()
{
    int new_location = this->get_new_location();

    if (this->field->out_of_field(new_location))
    {
        return;
    }

    // cout << name << " is going to move from " << location << " in location " << new_location << endl;

    if (this->field->is_empty(new_location))
    {

        this->move(new_location);
        // cout << new_location << " was empty  so moved to " << location << endl;
        return;
    }

    // cout << new_location << " was occupy so fight with " << this->field->get_fighter(new_location)->get_name() << endl;
    this->fight_with(this->field->get_fighter(new_location));
}
void Fighter::move(int location)
{
    this->field->update_location(this->location, location);
    this->location = location;
}
void Fighter::fight_with(Fighter *opponent)
{
    while (this->is_alive() && opponent->is_alive())
    {

        int who_is_turn = rand() % 2;
        if (who_is_turn == MY_TURN)
        {
            get_tired(opponent);
        }
        else
        {
            get_tired(this);
        }

        // cout << this->get_name() << this->health << " VS " << opponent->get_name() << this->get_health() << endl;
    }

    if (this->is_alive())
    {
        // cout << endl
        //      << this->name << " killed " << opponent->name
        //      << endl;
        this->move(opponent->location);
        return;
    }
    // cout << opponent->name << " killed " << this->name << endl;
}
void Fighter::get_tired(Fighter *fighter)
{
    fighter->health -= 1;
    if (fighter->health == 0)
    {
        fighter->is_dead = true;
    }
}

int Fighter::get_new_location()
{
    int direction;
    if (this->location == 0)
    {
        direction = RIGHT;
    }
    else if (this->location == this->field->size() - 1)
    {
        direction = LEFT;
    }
    else
    {
        direction = rand() % 2;
    }

    if (direction == LEFT)
    {
        return this->location - 1;
    }
    else
    {
        return this->location + 1;
    }
}

BattleField::BattleField(int battle_size, int fighter_num)
{
    battle_container = vector<Fighter *>(battle_size, NULL);

    for (int i = 0; i < fighter_num; i++)
    {
        int location = find_an_empty_location();
        Fighter *f = new Fighter('a' + i, location, this);
        set_fighter_in_battle(f, location);
    }
}
void BattleField::start_fight()
{
    while (this->winner_doesnot_selected())
    {
        cout << *this;
        // cin.get();
        for (int i = 0; i < fighter_container.size(); i++)
        {
            if (fighter_container[i]->is_alive())
            {
                // cout << fighter_container[i]->get_name() << " is going to fight.\n";
                fighter_container[i]->play_a_round();
            }
        }
    }
}
bool BattleField::out_of_field(int location)
{
    return location < 0 || location >= this->battle_container.size();
}

bool BattleField::winner_doesnot_selected()
{
    int fighters = 0;

    for (int i = 0; i < fighter_container.size(); i++)
    {
        if (fighter_container[i]->is_alive())
            fighters += 1;
    }

    return fighters > 1;
}

int BattleField::size()
{
    return battle_container.size();
}
Fighter *BattleField::get_fighter(int index)
{
    return battle_container[index];
}
bool BattleField::is_empty(int location)
{
    return battle_container[location] == 0 || !battle_container[location]->is_alive();
}
void BattleField::update_location(int old_location, int new_location)
{
    this->battle_container[new_location] = this->battle_container[old_location];
    this->battle_container[old_location] = 0;
}
void BattleField::set_fighter_in_battle(Fighter *f, int location)
{
    battle_container[location] = f;
    fighter_container.push_back(f);
}
int BattleField::find_an_empty_location()
{
    int battle_size = battle_container.size();
    int location = rand() % battle_size;
    while (true)
    {
        int location = rand() % battle_size;
        if (this->is_empty(location))
            return location;
    }
}
void BattleField::print_winner()
{
    for(int i = 0 ; i < fighter_container.size() ; i++)
    {
        if(fighter_container[i]->is_alive())
        {
            cout << *(fighter_container[i]) << " WON\n";
        }
    }
}

int main()
{
    srand(time(0));

    BattleField b(20, 5);
    // cout << b;
    b.start_fight();

    b.print_winner();

    return 0;
}