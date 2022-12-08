#include <iostream>
#include <string>

using namespace std;

struct move
{
    int x_delta;
    int y_delta;
};

struct point
{
    int x;
    int y;
};

const int COL_NUM = 6;
const int ROW_NUM = 6;
const int MOVE_NUM = 8;

int board[ROW_NUM][COL_NUM];
struct move moves[MOVE_NUM] = {
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1}};
int move_counter = 1;

void mark(struct point start_point)
{
    board[start_point.x][start_point.y] = ++move_counter;
}

void un_mark(struct point start_point)
{
    board[start_point.x][start_point.y] = 0;
    move_counter -= 1;
}

void reset_board(point start_point)
{
    for (int i = 0; i < ROW_NUM; i++)
        for (int j = 0; j < COL_NUM; j++)
            board[i][j] = 0;
    board[start_point.x][start_point.y] = move_counter;
}

void print_board()
{
    for (int i = 0; i < ROW_NUM; i++)
    {
        for (int j = 0; j < COL_NUM; j++)
        {
            string space = "";
            if (board[i][j] >= 10)
                space = "  ";
            else
                space = "   ";

            cout << board[i][j] << space;
        }
        cout << endl;
    }
}

point set_start_point()
{
    struct point start_point;
    // cout << "Enter start x: ";
    // cin >> start_point.x;
    start_point.x = 2;
    // cout << "Enter start y: ";
    // cin >> start_point.y;
    start_point.y = 3;
    return start_point;
}

void move_start_point_forward(struct point &start_point, struct move move)
{
    start_point.x += move.x_delta;
    start_point.y += move.y_delta;
}

bool is_out_of_board(struct point point)
{
    if (point.x > ROW_NUM - 1 || point.x < 0 || point.y > COL_NUM - 1 || point.y < 0)
        return true;
    return false;
}

void move_start_point_backward(struct point &point, struct move move)
{
    point.x += (-1 * move.x_delta);
    point.y += (-1 * move.y_delta);
}

bool found_a_tour(struct point start_point)
{
    if (move_counter == ROW_NUM * COL_NUM)
        return true;

    for (int i = 0; i < MOVE_NUM; i++)
    {
        move_start_point_forward(start_point, moves[i]);
        // cin.get();
        cout << "Move = " << moves[i].x_delta << " " << moves[i].y_delta << endl;
        cout << "new point = " << start_point.x << " " << start_point.y << endl;
        if (is_out_of_board(start_point))
        {
            move_start_point_backward(start_point, moves[i]);
            cout << "was out of board => point is = " << start_point.x << " " << start_point.y << endl;
            continue;
        }

        if (board[start_point.x][start_point.y] != 0)
        {
            move_start_point_backward(start_point, moves[i]);
            cout << "it is full => point is = " << start_point.x << " " << start_point.y << endl;
            continue;
        }
        cout << "new point = " << start_point.x << " " << start_point.y << endl;

        mark(start_point);
        // print_board();
        cout << "\n--------------------------\n";
        // cin.get();
        if (found_a_tour(start_point))
        {
            return true;
        }
        un_mark(start_point);
    }

    return false;
}

void solve_from(struct point start_point)
{
    if (found_a_tour(start_point))
    {
        print_board();
    }
    else
    {
        cout << "Failed to solve!\n";
    }
}

int main()
{

    struct point start_point = set_start_point();

    reset_board(start_point);
    cout << "start point = " << start_point.x << " " << start_point.y << endl;

    print_board();
    // for (int i = 0; i <= ROW_NUM; i++)
    // {
    //     for (int j = 0; j <= COL_NUM; j++)
    //     {
    //         struct point p = {i, j};
    //         cout << "start point = " << p.x << " " << p.y << endl;
    //         solve_from(p);
    //     }
    // }

    solve_from(start_point);

    return 0;
}