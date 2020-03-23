#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[1001][1001];
int max;

int Min(int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
			return c;
		else
			return b;
	}
	else
	{
		if (a > c)
			return c;
		else
			return a;
	}
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < line.size(); j++)
		{
			map[i][j] = line[j] - 48;
		}
	}
}

void Solution()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if (map[i][j] == 0)
				continue;
			map[i][j] = Min(map[i - 1][j], map[i][j - 1], map[i - 1][j - 1]) + 1;
		}
	}
}

int main()
{
	Input();
	Solution();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < map[i][j])
				max = map[i][j];
		}
	}
	cout << max * max;
}