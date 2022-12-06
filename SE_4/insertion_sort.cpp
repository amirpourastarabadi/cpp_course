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

void write_inputs(vector<int> inputs)
{
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << inputs[i] << ' ';
    }

    cout << endl;
}

void swap(vector<int> &inputs, int first_index, int second_index)
{
    int temp = inputs[first_index];
    inputs[first_index] = inputs[second_index];
    inputs[second_index] = temp;
}

int find_min_index(vector<int> inputs, int index)
{
    int index_of_minimum = index;
    for(int i = index + 1; i < inputs.size(); i++)
    {
        if(inputs[i] < inputs[index_of_minimum]) 
            index_of_minimum = i;
    }

    return index_of_minimum;
}

void insertion_sort(vector<int> &inputs, int index = 0)
{
    if (index == inputs.size() - 1)
        return;

    int min_index = find_min_index(inputs, index);
    
    swap(inputs, index, min_index);

    insertion_sort(inputs, index + 1);
}

int main()
{
    vector<int> inputs = read_inputs();

    insertion_sort(inputs); // recursive

    write_inputs(inputs);

    return 0;
}