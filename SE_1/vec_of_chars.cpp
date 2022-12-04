#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<char> chars(100, 'A');
    for(int i = 0; i < chars.size(); i++)
    {
        cout << chars[i] << " ";
    }
    return 0;
}