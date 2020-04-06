#include <iostream>
#include <vector>
#define INF 1001

using namespace std;
int map[1001][1001];
int mileage[1001][100];

pair<int, vector<int>> dist[101]; // 거리/이전인덱스
int currentMileage;
vector<int> ableMileage;
bool visited[1001];

int Min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

int FindMinNumber(int N)
{
	int min = INF;
	int minIndex;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
			continue;

		if (dist[i].first < min)
		{
			min = dist[i].first;
			minIndex = i;
		}
	}
	return minIndex;
}

void DFSFind(int current)
{
	for (int i = 0; i < dist[current].second.size(); i++)
	{
		currentMileage += mileage[current][dist[current].second[i]];
		DFSFind(dist[current].second[i]);
	}
}

void Dijkstra(int start, int N)
{
	for (int i = 1; i <= N; i++)
	{
		dist[i].first = map[start][i];
		if (map[start][i] > 0 && map[start][i] < INF)
			dist[i].second.push_back(start);
	}
	visited[start] = true;

	for (int i = 0; i < N - 2; i++)
	{
		int currentNumber = FindMinNumber(N);
		visited[currentNumber] = true;

		for (int target = 1; target <= N; target++)
		{
			if (visited[target])
				continue;
			if (dist[currentNumber].first + map[currentNumber][target] <= dist[target].first)
			{
				if (dist[currentNumber].first + map[currentNumber][target] < dist[target].first)
				{
					dist[target].second.clear();
					dist[target].second.push_back(currentNumber);
				}
				else if (dist[currentNumber].first + map[currentNumber][target] == dist[target].first)
					dist[target].second.push_back(currentNumber);
				dist[target].first = dist[currentNumber].first + map[currentNumber][target];
			}
		}
	}
}

pair<int,int> Solution(int n, int k, vector<vector<int>>paths)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < paths.size(); i++)
	{
		int start = paths[i][0];
		int end = paths[i][1];
		map[start][end] = paths[i][2];
		map[end][start] = paths[i][2];
		mileage[start][end] = paths[i][3];
		mileage[end][start] = paths[i][3];
	}

	Dijkstra(1, n);

	for (int i = 0; i < dist[k].second.size(); i++)
	{
		currentMileage = 0;
		currentMileage += mileage[k][dist[k].second[i]];
		DFSFind(dist[k].second[i]);
		ableMileage.push_back(currentMileage);
	}

	int maxValue = ableMileage[0];
	for (int i = 1; i < ableMileage.size(); i++)
	{
		if (ableMileage[i] > maxValue)
			maxValue = ableMileage[i];
	}

	return { dist[k].first,maxValue };
}

int main()
{
	pair<int,int>answer =
	Solution(5, 4,
		{ {1,5,1,1}
		,{1,2,4,3}
		,{1,3,3,2}
		,{2,5,2,1}
		,{2,4,2,3}
		,{3,4,2,2} });
	cout << answer.first << answer.second;
}