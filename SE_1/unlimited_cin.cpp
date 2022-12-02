#include <iostream>
#include <string>

using namespace std;

int main()
{
    string prev = "";
    string current;

    while (cin >> current)
    {
        if(current == prev){
            cout << "word '" << current << "' repeated." << endl;
        }
        prev = current;
    }
    

}
