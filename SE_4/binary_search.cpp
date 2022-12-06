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

int prompt_user()
{
    cout << "What are you looking for?" << endl;

    int target;
    cin >> target;

    return target;
}

int search(vector<int> inputs, int target, int from, int to)
{
    if (from > to)
    {
        return -1;
    }

    int mid = (from + to) / 2;
    if (inputs[mid] == target)
    {
        return mid;
    }

    if (inputs[mid] > target)
    {
        return search(inputs, target, from, mid - 1);
    }

    return search(inputs, target, mid + 1, to);
}

void notice_user(int result)
{
    if (result == -1)
    {
        cout << "Not Found";
        return;
    }

    cout << "target find in " << result << " index" << endl;
}

int main()
{
    vector<int> inputs = read_inputs(); // in sorted order

    int target = 9;

    int result = search(inputs, target, 0, inputs.size() - 1);

    notice_user(result);

    return 0;
}