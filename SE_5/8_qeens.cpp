#include <iostream>
#include <cmath>

using namespace std;

const int NUMBWER_OF_ROWS = 8;
const int NUMBWER_OF_COLS = 8;

int col_of_queen_in_rows[NUMBWER_OF_ROWS];

void reset_board()
{
    for (int row = 0; row < NUMBWER_OF_ROWS; row++)
        col_of_queen_in_rows[row] = -1;
}

void print_board()
{
    for (int row = 0; row < NUMBWER_OF_ROWS; row++)
    {
        for (int col = 0; col < NUMBWER_OF_COLS; col++)
            cout << (col == col_of_queen_in_rows[row] ? "Q" : ".");
        cout << endl;
    }
    cin.get();
}
struct point
{
    int row;
    int col;
};

bool threat(point p1, point p2)
{
    if (p1.row == p2.row || p1.col == p2.col || abs(p1.row - p2.row) == abs(p1.col - p2.col))
        return true;
    return false;
}

bool can_put_at(int row, int col)
{
    struct point p1 = {row, col};
    for (int row = 0; row < p1.row; row++)
    {
        struct point p2 = {row, col_of_queen_in_rows[row]};
        if (threat(p1, p2))
            return false;
    }
    return true;
}

bool solve(int row)
{
    if (row == NUMBWER_OF_ROWS)
        return true;

    for (int col = 0; col < NUMBWER_OF_COLS; col++)
    {
        if (can_put_at(row, col))
        {
            col_of_queen_in_rows[row] = col;
            if (solve(row + 1))
                print_board();
            col_of_queen_in_rows[row] = -1; 
        }
    }

    return false;
}

int main()
{
    reset_board();

    solve(0);

    return 0;
}