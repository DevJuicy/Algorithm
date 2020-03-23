#include <iostream>
#include <vector>

using namespace std;

int N;
int map[101][101];
long DP[101][101];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Solution()
{
	DP[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (DP[i][j] == 0 || (i == N - 1 && j == N - 1))
				continue;

			int dist = DP[i][j];
			int down = i + map[i][j];
			int left = j + map[i][j];

			if (down < N)
				DP[down][j] += DP[i][j];
			if (left < N)
				DP[i][left] += DP[i][j];
		}
	}
}

int main()
{
	Input();
	Solution();
	cout << DP[N - 1][N - 1];
}