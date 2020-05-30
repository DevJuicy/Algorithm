#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000

using namespace std;

int N, K;
int adj[101][101];
int dist[101];
bool visited[101];

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
	//6 10
	//0 1 2
	//0 2 5
	//0 3 1
	//1 2 3
	//1 3 2
	//2 3 3
	//2 4 1
	//2 5 5
	//3 4 1
	//4 5 2

	// N : 총 크기,  K : 노드 갯수
	cin >> N >> K;

	// 자기자신을 제외한 온맵을 INF로 초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			adj[i][j] = INF;
		}
	}

	// y,x의 값을 받아들임
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
	// 이미 확정된 곳을 제외한 가장 거리가 짧은 노드 반환
	int min = INF;
	int minIndex = 0;
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
	// dist 거리 초기화
	for (int i = 0; i < N; i++)
		dist[i] = adj[start][i];
	visited[start] = true;



	for (int i = 0; i < N-2; i++)
	{
		int currentMinNumber = FindMinNumber();
		visited[currentMinNumber] = true;

		for (int target = 0; target < N; target++)
		{
			// 확정된 노드는 건너뛰고
			if (visited[target])
				continue;

			// 현재 최소 넘버에서 새로 거리를 갱신해줌
			if (dist[currentMinNumber] + adj[currentMinNumber][target] < dist[target])
			{
				dist[target] = dist[currentMinNumber] + adj[currentMinNumber][target];
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