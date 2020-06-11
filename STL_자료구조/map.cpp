#include <map>
#include <iostream>
using namespace std;
int main()
{
    map<string, int> m;

    if (m.find("f") == m.end())
    {
        // not found
    }
    else
    {
        // found
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << "key : " << it->first << " " << "value : " << it->second << '\n';
    }
}