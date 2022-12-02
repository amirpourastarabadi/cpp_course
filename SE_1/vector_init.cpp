#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> temps(10);
    for (int i = 0; i < 10; i++)
    {
        cout << temps[i] << ',';
    }
    cout << endl;

    vector<double> temps2(10, 1.2);
    for (int i = 0; i < 10; i++)
    {
        cout << temps2[i] << ',';
    }
    cout << endl;

    // vector<string> temps3(10, 'amir');  invalid
    vector<string> temps3(10);
    for (int i = 0; i < 10; i++)
    {
        temps3[i] = "amir";
        cout << temps3[i] << ',';
    }
    cout << endl;

    vector<vector<int>> temps4(3, vector<int>(4, 3));
    for (int i = 0; i < temps4.size(); i++)
    {
        for (int j = 0; j < temps4[i].size(); j++)
        {
            cout << temps4[i][j] << ',';
        }
        cout << endl;
    }

}