#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> Network;
typedef vector<int> LineOrders;

Network read_network(int net_size)
{
    Network network;
    string line;

    for (int i = 0; i < net_size; i++)
    {
        cin >> line;

        network.push_back(line);
    }

    return network;
}

vector<int> read_lines(int lines_count)
{
    LineOrders line_orders;

    int order;

    for (int i = 0; i < lines_count; i++)
    {
        cin >> order;
        line_orders.push_back(order);
    }

    return line_orders;
}

void compare_network(Network &network, vector<int> &line_orders)
{
    for (int i = 0; i < network.size() - 1; i++)
    {
        for (int j = i + 1; j < network.size(); j++)
        {
            if (network[j][i] == '-')
            {
                continue;
            }
            if (network[j][i] == network[i][i])
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

    Network network = read_network(lines_cout);

    LineOrders line_orders = read_lines(lines_cout);

    compare_network(network, line_orders);

    printResult(line_orders);

    return 0;
}