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

	// N : �� ũ��,  K : ��� ����
	cin >> N >> K;

	// �ڱ��ڽ��� ������ �¸��� INF�� �ʱ�ȭ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			adj[i][j] = INF;
		}
	}

	// y,x�� ���� �޾Ƶ���
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
	// �̹� Ȯ���� ���� ������ ���� �Ÿ��� ª�� ��� ��ȯ
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
	// dist �Ÿ� �ʱ�ȭ
	for (int i = 0; i < N; i++)
		dist[i] = adj[start][i];
	visited[start] = true;



	for (int i = 0; i < N-2; i++)
	{
		int currentMinNumber = FindMinNumber();
		visited[currentMinNumber] = true;

		for (int target = 0; target < N; target++)
		{
			// Ȯ���� ���� �ǳʶٰ�
			if (visited[target])
				continue;

			// ���� �ּ� �ѹ����� ���� �Ÿ��� ��������
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