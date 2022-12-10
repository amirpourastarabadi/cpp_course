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
struct move moves[MOVE_NUM] = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
int move_counter = 1;

void mark(struct point start_point)
{
    board[start_point.x][start_point.y] = move_counter;
    move_counter += 1;
}

void un_mark(struct point start_point)
{
    board[start_point.x][start_point.y] = 0;
    move_counter -= 1;
}

void reset_board(struct point start_point)
{
    for (int i = 0; i < ROW_NUM; i++)
        for (int j = 0; j < COL_NUM; j++)
            board[i][j] = 0;
    mark(start_point);
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
    start_point.x = 6;
    // cout << "Enter start y: ";
    // cin >> start_point.y;
    start_point.y = 6;
    return start_point;
}

void move_start_point_forward(struct point &start_point, struct move move)
{
    start_point.x += move.x_delta;
    start_point.y += move.y_delta;
}

bool is_out_of_board(struct point point)
{
    if (point.x > ROW_NUM || point.x < 0 || point.y > COL_NUM || point.y < 0)
        return true;
    return false;
}

void move_start_point_backward(struct point &point, struct move move)
{
    point.x += (-1 * move.x_delta);
    point.y += (-1 * move.y_delta);
}

bool is_solved(struct point start_point)
{
    if (move_counter == ROW_NUM * COL_NUM)
        return true;

    for (int i = 0; i < MOVE_NUM; i++)
    {
        move_start_point_forward(start_point, moves[i]);
        if (is_out_of_board(start_point))
        {
            move_start_point_backward(start_point, moves[i]);
            continue;
        }

        if (board[start_point.x][start_point.y] != 0)
        {
            continue;
        }
        mark(start_point);
        if (is_solved(start_point))
        {
            return true;
        }
        un_mark(start_point);
    }

    return false;
}

void solve_from(struct point start_point)
{
    if (is_solved(start_point))
    {
        print_board();
    }
    else
    {
        cout << "Failed to solve!";
    }
}

int main()
{

    struct point start_point = set_start_point();

    reset_board(start_point);

    print_board();

    solve_from(start_point);

    return 0;
}