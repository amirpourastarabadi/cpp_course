#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_network(int net_size)
{
    vector<string> lines;
    string line;

    for (int i = 0; i < net_size; i++)
    {
        cin >> line;

        lines.push_back(line);
    }

    return lines;
}

vector<int> read_lines(int lines_count)
{
    vector<int> line_orders;

    int order;

    for (int i = 0; i < lines_count; i++)
    {
        cin >> order;
        line_orders.push_back(order);
    }

    return line_orders;
}

void compare_network(vector<string> &lines, vector<int> &line_orders)
{
    for (int i = 0; i < lines.size() - 1; i++)
    {
        for (int j = i + 1; j < lines.size(); j++)
        {
            if (lines[j][i] == '-')
            {
                continue;
            }
            if (lines[j][i] == lines[i][i])
            {
                if (line_orders[i] > line_orders[j])
                {
                    int temp = line_orders[i];
                    line_orders[i] = line_orders[j];
                    line_orders[j] = temp;
                }
            }
        }
    }
}

void printResult(vector<int> line_orders)
{
    for (int i = 0; i < line_orders.size(); i++)
    {
        cout << line_orders[i] << ' ';
    }
}

int main()
{

    int lines_cout;
    cin >> lines_cout;

    vector<string> lines = read_network(lines_cout);
    vector<int> line_orders = read_lines(lines_cout);

    compare_network(lines, line_orders);

    printResult(line_orders);

    return 0;
}