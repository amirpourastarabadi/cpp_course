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

int sum_list(vector<int> inputs, int index = 0)
{
    if(index == inputs.size()) return 0;

    return inputs[index] + sum_list(inputs, index + 1);
}

int main()
{
    vector<int> inputs = read_inputs();

    int sum = sum_list(inputs); // recursive

    cout << "SUM = " << sum << endl;

    return 0;
}