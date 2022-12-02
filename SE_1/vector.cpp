#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> temps;
    double temp;
    cout << "Enter temps...";

    while (cin >> temp)
    {
        temps.push_back(temp);
    }

    double sum = 0.0;

    for(int i =0 ; i < temps.size(); i++){
        sum += temps[i];
    }

    cout << "Mean = " << sum / temps.size() << endl;
    
    sort(temps.begin(), temps.end());

    cout << "Mean = " << temps[temps.size() / 2] << endl;
    
}