#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef vector<char> Alephabetvec;

void printVec(vector<char> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
} 

int main()
{
    Alephabetvec capitals(26);
    
    iota(capitals.begin(), capitals.end(), 'A');

    printVec(capitals);

    return 0;
}