#include <string>
#include <vector>
#include <iostream>
#define INF 1000000

using namespace std;

int adj[201][201];
bool visited[201];

int FindMinNumber(int nodeSize, vector<int> dist)
{
	// �̹� Ȯ���� ���� ������ ���� �Ÿ��� ª�� ��� ��ȯ
	int min = INF;
	int minIndex = 0;
	for (int i = 1; i <= nodeSize; i++)
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

vector<int> Dijkstra(int start, int nodeSize)
{
	// start ���κ��� �� ������� �ִܰŸ��� ��� ����
	vector<int> dist;
	dist.push_back(0); // 0�� �ε����� �� ���� ���� ����

	// �湮��� �ʱ�ȭ
	for (int i = 1; i <= nodeSize; i++)
		visited[i] = false;

	// dist �Ÿ� �ʱ�ȭ
	for (int i = 1; i <= nodeSize; i++)
		dist.push_back(adj[start][i]);
	visited[start] = true;

	for (int i = 0; i < nodeSize - 2; i++)
	{
		int currentMinNumber = FindMinNumber(nodeSize, dist);
		visited[currentMinNumber] = true;

		for (int target = 1; target <= nodeSize; target++)
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

	return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	vector<int> answerCandidate;
	answerCandidate.resize(n+1);

	int answer = INF;

	// �ڽ��� ������ N * N ��������� ���ڸ� ��� INF������ �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			adj[i][j] = INF;
		}
	}

	// �� ����� ������ ����� �Ÿ��� ��������
	for (int i = 0; i < fares.size(); i++)
	{
		adj[fares[i][0]][fares[i][1]] = fares[i][2];
		adj[fares[i][1]][fares[i][0]] = fares[i][2];
	}


	// �� ��忡�� �������� �ִܰŸ��� �������
	vector<int> startMinDistacne = Dijkstra(s, n); // s��忡�� �� ��������� �ִܰŸ��� ����
	vector<int> aMinDistacne = Dijkstra(a, n); // a��忡�� �� ��������� �ִܰŸ��� ����
	vector<int> bMinDistacne = Dijkstra(b, n); // b��忡�� �� ��������� �ִܰŸ��� ����

	// �� �迭���� �� �� ���� ���� ���� ���̴� �̸��̿ýô�.
	for (int i = 1; i <= n; i++)
	{
		answerCandidate[i] += startMinDistacne[i] + aMinDistacne[i] + bMinDistacne[i];

		if (answerCandidate[i] < answer && answerCandidate[i] > 0)
			answer = answerCandidate[i];
	}
	return answer;
}

int main()
{       // node, start, a, b
	//cout << 
	//	solution(6, 4, 6, 2,
	//	{
	//	{4,1,10},{3,5,24},{5,6,2},
	//	{3,1,41},{5,1,24},{4,6,50},
	//	{2,4,66},{2,3,22},{1,6,25}
	//	});

	//cout <<
	//	solution(7, 3, 4, 1,
	//		{
	//			{5,7,9},{4,6,4},{3,6,1},
	//		{3,2,3},{2,1,6}
	//		});

	//cout <<
	//	solution(6, 4, 5, 6,
	//		{
	//			{2,6,6},{6,3,7},{4,6,7},
	//		{6,5,11},{2,5,12},{5,3,20},{2,4,8},{4,3,9}
	//		});
}