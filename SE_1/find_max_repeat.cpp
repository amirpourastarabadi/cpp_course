#include <iostream>
#include <string>
#include <vector>

using namespace std;

void read_raw_data(vector<string> &container)
{
    string input;
    while (cin >> input)
    {
        container.push_back(input);
    }
}

vector<int> fill_hast_table(vector<string> raw_data)
{
    hash<string> hash_func;
    vector<int> table(10000, 0);

    for (int i = 0; i < raw_data.size(); i++)
    {
        int index = hash_func(raw_data[i]) % 10000;
        if (table[index])
        {
            table[index] += 1;
        }
        else
        {
            table[index] = 1;
        }
    }

    return table;
}

int find_max(vector<int> hash_table)
{
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < hash_table.size(); i++)
    {
        if (hash_table[i] > max)
        {
            max = hash_table[i];
            max_index = i;
        }
    }

    return max_index;
}

void report_max_repeat(int max_index, vector<string> raw_data)
{
    hash<string> hash_func;

    for (int i = 0; i < raw_data.size(); i++)
    {
        string key = raw_data[i];
        if ((hash_func(key) % 10000) == max_index)
        {
            cout << "MAX = " << key << endl;
            return;
        }
    }
}

int main()
{
    vector<string> raw_data;

    read_raw_data(raw_data);

    vector<int> hash_table = fill_hast_table(raw_data);

    int max_index = find_max(hash_table);

    report_max_repeat(max_index, raw_data);

    return 0;
}