#include <iostream>
#include <vector>

using namespace std;

int map[601][601];

int Min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int ABS(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

vector<vector<int>> Solution(int n, vector<vector<int>> bus_stop)
{
	vector<vector<int>> answer(n);

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			map[y][x] = ABS(bus_stop[0][0], y) + ABS(bus_stop[0][1], x);
		}
	}

	for (int i = 1; i < bus_stop.size(); i++)
	{
		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= n; x++)
			{
				map[y][x] = Min(ABS(bus_stop[i][0], y) + ABS(bus_stop[i][1], x),map[y][x]);
			}
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			answer[y - 1].push_back(map[y][x]);
		}
	}
	return answer;
}