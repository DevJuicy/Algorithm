#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[1001][1001];
int DP1[1001][1001];
int DP2[1001][1001];

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Debug()
{
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << DP1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << DP2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Solution()
{
	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		sum += map[0][i];
		DP1[0][i] = sum;
		DP2[0][i] = sum;
	}

	for (int i = 1; i < N; i++)
	{
		DP1[i][0] = DP1[i - 1][0] + map[i][0];
		DP2[i][M - 1] = DP2[i - 1][M - 1] + map[i][M - 1];
		for (int j = 1; j < M; j++)
		{
			DP1[i][j] = Max(DP1[i][j - 1] + map[i][j], DP1[i - 1][j] + map[i][j]);
			DP2[i][M - j - 1] = Max(DP2[i][M - j] + map[i][M - j - 1], DP1[i - 1][M - j - 1] + map[i][M - j - 1]);
		}
		for (int j = 0; j < M; j++)
		{
			DP1[i][j] = Max(DP1[i][j],DP2[i][j]);
			DP2[i][j] = DP1[i][j];
		}
	}
}

int main()
{
	Input();
	Solution();
	//Debug();
	cout << DP1[N - 1][M - 1];
}