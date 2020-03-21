#include <iostream>
#include <vector>

using namespace std;

int N;
int Lion[100001][3];

void Input()
{
	cin >> N;
}

void Solution()
{
	Lion[1][0] = 1;
	Lion[1][1] = 1;
	Lion[1][2] = 1;

	for (int i = 2; i <= N; i++)
	{
		Lion[i][0] = (Lion[i - 1][0] + Lion[i - 1][1] + Lion[i - 1][2]) % 9901;
		Lion[i][1] = (Lion[i - 1][0] + Lion[i - 1][2]) % 9901;
		Lion[i][2] = (Lion[i - 1][0] + Lion[i - 1][1]) % 9901;
	}
}

int main()
{
	Input();
	Solution();
	cout << (Lion[N][0] + Lion[N][1] + Lion[N][2]) % 9901 << endl;
}