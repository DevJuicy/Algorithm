#include <iostream>

using namespace std;

long long stair[101];

int main()
{
	stair[1] = 1;
	stair[2] = 2;
	stair[3] = 4;

	for (int i = 4; i <= 100; i++)
	{
		stair[i] = stair[i - 1] + stair[i - 2] + stair[i - 3];
	}
	cout << stair[100];
}