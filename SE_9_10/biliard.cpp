#include <iostream>
#include <string>
#include <cmath>

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
    int get_diameter()
    {
        return sqrt(this->v_x * this->v_x + this->v_y * this->v_y);
    }

    int get_reflection_angle()
    {
        if (v_x == 0 || v_y == 0)
        {
            return acos(90);
        }

        return acos(((v_x * v_x) + (v_y * v_y) - (get_diameter() * get_diameter())) / (2 * v_x * v_y));
    }

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
        width = 50;
        length = 50;
    }

    Table(int width, int length)
    {
        if (width <= 0 || length <= 0)
            abort();
        this->width = width;
        this->length = length;
    }

    void set_new_pos(Point *position, Velocity *v, int delta_t)
    {
        for (int i = 0; i < delta_t; i++)
        {
            position->set_pos(position->get_x() + v->get_vx(), position->get_y() + v->get_vy());

            while (!this->check_in_table(position->get_x(), position->get_y()))
            {
                this->reflect(position, v);
            }
        }
    }

    void reflect(Point *position, Velocity *v)
    {
        this->reflect_vx(v);

        this->reflect_vy(v);

        this->reflect_x(position);

        this->reflect_y(position);
    }

    void reflect_vx(Velocity *v)
    {
        v->set_v_vector(v->get_vx() * -1, v->get_vy());
    }

    void reflect_vy(Velocity *v)
    {
        v->set_v_vector(v->get_vx(), v->get_vy() * -1);
    }

    void reflect_x(Point *p)
    {
        if (p->get_x() > this->width)
        {
            int new_x = this->width - (p->get_x() - this->width);
            p->set_pos(new_x, p->get_y());
        }

        if (p->get_x() < 0)
        {
            int new_x = p->get_x() * -1;
            p->set_pos(new_x, p->get_y());
        }
    }

    void reflect_y(Point *p)
    {
        if (p->get_y() > this->length)
        {
            int new_y = this->length - (p->get_y() - this->length);
            p->set_pos(p->get_x(), new_y);
        }

        if (p->get_y() < 0)
        {
            int new_y = p->get_y() * -1;
            p->set_pos(p->get_x(), new_y);
        }
    }

    bool check_in_table(int x, int y)
    {
        return (x <= this->width && x >= 0) && (y <= this->length && y >= 0);
    }

    string to_string()
    {
        return std::to_string(this->length) + " * " + std::to_string(this->width);
    }

private:
    int width;
    int length;
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
        this->velocity = v;
        table->set_new_pos(&(this->position), &(this->velocity), delta_t);
    }

    string to_string()
    {
        return "position = " + this->position.to_sting() +
               "\n\tvelocity = " + this->velocity.to_string();
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

    b.hit(Velocity(1, 1), 50);
    
    cout << "final report = \n\t" << b.to_string() << endl;

    return 0;
}