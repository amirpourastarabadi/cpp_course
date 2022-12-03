#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int lines_cout;
    vector<int> line_orders;
    cin >> lines_cout;

    string line;
    int order;

    vector<string> lines;

    for (int i = 0; i < lines_cout; i++)
    {
        cin >> line;

        lines.push_back(line);
    }

    for (int i = 0; i < lines_cout; i++)
    {
        cin >> order;
        line_orders.push_back(order);
    }

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

    for (int i = 0; i < lines_cout; i++)
    {
        cout << line_orders[i] << ' ';
    }

    return 0;
}