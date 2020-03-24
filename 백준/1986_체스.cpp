#include <iostream>
#include <vector>

using namespace std;

int N, M, queen, knight, pawn;
int map[1001][1001];
int answer;

void Debug()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 0)
				answer++;
		}
	}
	cout << answer;
}

void Input()
{
	cin >> N >> M;
	cin >> queen;
	for (int i = 0; i < queen; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}

	cin >> knight;
	for (int i = 0; i < knight; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 2;
	}

	cin >> pawn;
	for (int i = 0; i < pawn; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 3;
	}
}

void Queen(int i, int j)
{
	int y = i;
	int x = j;
	while (y > 1)
	{
		y--;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (y < N)
	{
		y++;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (x > 1)
	{
		x--;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (x < M)
	{
		x++;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (y > 1 && x > 1)
	{
		y--;
		x--;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (y < N && x > 1)
	{
		y++;
		x--;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (y > 1 && x < M)
	{
		y--;
		x++;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}

	y = i;
	x = j;
	while (y < N && x < M)
	{
		y++;
		x++;
		if (map[y][x] > 0)
			break;
		map[y][x] = -1;
	}
}

void Knight(int i, int j)
{
	if (i > 2)
	{
		if (j > 0)
		{
			if (map[i - 2][j - 1] == 0)
				map[i - 2][j - 1] = -1;
		}
		if (j < M)
		{
			if (map[i - 2][j + 1] == 0)
				map[i - 2][j + 1] = -1;
		}
	}

	if (i < N - 1)
	{
		if (j > 0)
		{
			if (map[i + 2][j - 1] == 0)
				map[i + 2][j - 1] = -1;
		}
		if (j < M)
		{
			if (map[i + 2][j + 1] == 0)
				map[i + 2][j + 1] = -1;
		}
	}

	if (j > 2)
	{
		if (i > 0)
		{
			if (map[i - 1][j - 2] == 0)
				map[i - 1][j - 2] = -1;
		}
		if (j < N)
		{
			if (map[i + 1][j - 2] == 0)
				map[i + 1][j - 2] = -1;
		}
	}

	if (j < M - 1)
	{
		if (i > 0)
		{
			if (map[i - 1][j + 2] == 0)
				map[i - 1][j + 2] = -1;
		}
		if (j < N)
		{
			if (map[i + 1][j + 2] == 0)
				map[i + 1][j + 2] = -1;
		}
	}
}

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			switch (map[i][j])
			{
			case 1:
				Queen(i, j);
				break;
			case 2:
				Knight(i, j);
				break;
			default:
				break;
			}
		}
	}
}

int main()
{
	Input();
	Solution();
	Debug();
}