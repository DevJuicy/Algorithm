#include <iostream>
#include <vector>
#include <queue>
#define INF 10000

using namespace std;

int N, K;
int adj[101][101];
int dist[101];
bool visited[101];

int Min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

void DEBUG()
{
	for (int i = 0; i < N; i++)
	{
		cout << dist[i] << " ";
	}
	cout << endl;
}

void Input()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			adj[i][j] = INF;
		}
	}

	for (int i = 0; i < K; i++)
	{
		int y, x, value;
		cin >> y >> x >> value;
		adj[y][x] = value;
		adj[x][y] = value;
	}
}

int FindMinNumber()
{
	int min = INF;
	int minIndex;
	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;

		if (dist[i] < min)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void Dijkstra(int start)
{
	for (int i = 0; i < N; i++)
		dist[i] = adj[start][i];
	visited[start] = true;

	for (int i = 0; i < N-2; i++)
	{
		int currentNumber = FindMinNumber();
		visited[currentNumber] = true;

		for (int target = 0; target < N; target++)
		{
			if (visited[target])
				continue;
			if (dist[currentNumber] + adj[currentNumber][target] < dist[target])
			{
				dist[target] = dist[currentNumber] + adj[currentNumber][target];
			}
		}
	}
}

void Solution()
{
	Dijkstra(0);
	DEBUG();
}

int main()
{
	Input();
	Solution();
}