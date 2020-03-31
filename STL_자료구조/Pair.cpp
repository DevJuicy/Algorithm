#include <iostream>
#include <vector>

using namespace std;

pair<int, int> p;

int main()
{
	p = make_pair(5, 4);
	cout << p.first << p.second;
}