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
}