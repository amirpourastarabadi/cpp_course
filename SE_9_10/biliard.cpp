#include <iostream>
#include <string>

using namespace std;

class Point
{
public:
    Point() { this->set_pos(0, 0); }
    Point(int x, int y) { this->set_pos(x, y); }
    int get_x() { return this->x; }
    int get_y() { return this->y; }
    void set_pos(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    string to_sting()
    {
        return '(' + std::to_string(this->x) + ", " + std::to_string(this->y) + ')';
    }

private:
    int x;
    int y;
};

class Velocity
{
public:
    Velocity(int v_x, int v_y) { this->set_v_vector(v_x, v_y); }
    Velocity() { this->set_v_vector(0, 0); }
    void set_v_vector(int v_x, int v_y)
    {
        this->v_x = v_x;
        this->v_y = v_y;
    }
    int get_vx() { return this->v_x; };
    int get_vy() { return this->v_y; };
    string to_string()
    {
        return '(' + std::to_string(this->v_x) + ", " + std::to_string(this->v_y) + ')';
    }

private:
    int v_x;
    int v_y;
};

class Table
{
public:
    Table()
    {
        width = 80;
        height = 100;
    }

    Table(int width, int height)
    {
        if (width <= 0 || height <= 0)
            abort();
        this->width = width;
        this->height = height;
    }

    void set_new_pos(Point *position, Velocity v, int delta_t)
    {
        for (int i = 0; i < delta_t; i++)
        {
            if (this->check_in_table(position->get_x() + v.get_vx(), position->get_y() + v.get_vy()))
            {
                position->set_pos(position->get_x() + v.get_vx(), position->get_y() + v.get_vy());
                continue;
            }

            // todo: handle if point touch the edges
        }
    }

    bool check_in_table(int x, int y)
    {
        return x <= this->width && y <= this->height;
    }

    string to_string()
    {
        return std::to_string(this->height) + " * " + std::to_string(this->width);
    }

private:
    int width;
    int height;
};

class Ball
{
public:
    Ball(Point position, Velocity velocity, Table *table)
    {
        this->position = position;
        this->velocity = velocity;
        this->table = table;
    };
    void hit(Velocity v, int delta_t)
    {
        table->set_new_pos(&(this->position), v, delta_t);
    }
    string to_string()
    {
        return "position = " + this->position.to_sting() +
               "\nvelocity = " + this->velocity.to_string();
    }

private:
    Point position;
    Velocity velocity;
    Table *table;
};

int main()
{
    Table t = Table();
    Ball b = Ball(Point(10, 10), Velocity(0, 0), &t);

    return 0;
}