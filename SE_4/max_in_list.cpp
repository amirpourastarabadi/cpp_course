#include <iostream>
#include <vector>

using namespace std;

vector<int> read_inputs()
{
    vector<int> inputs;
    int input;
    while (cin >> input)
    {
        inputs.push_back(input);
    }
    return inputs;
}

int find_max(vector<int> inputs, int index = 0)
{
    if (index == inputs.size() - 1)
        return inputs[index];

    return max(inputs[index], find_max(inputs, index + 1));
}

int main()
{
    vector<int> inputs = read_inputs();

    int max = find_max(inputs); // recursive

    cout << "MAX = " << max << endl;

    return 0;
}