#include <string>
#include <vector>
#include <iostream>
#define INF 1000000

using namespace std;

int adj[201][201];
bool visited[201];

int FindMinNumber(int nodeSize, vector<int> dist)
{
	// 이미 확정된 곳을 제외한 가장 거리가 짧은 노드 반환
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
	// start 노드로붙터 각 노드들까지 최단거리를 담는 변수
	vector<int> dist;
	dist.push_back(0); // 0번 인덱스는 안 세기 위해 넣음

	// 방문기록 초기화
	for (int i = 1; i <= nodeSize; i++)
		visited[i] = false;

	// dist 거리 초기화
	for (int i = 1; i <= nodeSize; i++)
		dist.push_back(adj[start][i]);
	visited[start] = true;

	for (int i = 0; i < nodeSize - 2; i++)
	{
		int currentMinNumber = FindMinNumber(nodeSize, dist);
		visited[currentMinNumber] = true;

		for (int target = 1; target <= nodeSize; target++)
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

	return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	vector<int> answerCandidate;
	answerCandidate.resize(n+1);

	int answer = INF;

	// 자신을 제외한 N * N 정방행렬의 인자를 모두 INF값으로 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			adj[i][j] = INF;
		}
	}

	// 각 노드의 인접한 노드의 거리를 갱신해줌
	for (int i = 0; i < fares.size(); i++)
	{
		adj[fares[i][0]][fares[i][1]] = fares[i][2];
		adj[fares[i][1]][fares[i][0]] = fares[i][2];
	}


	// 각 노드에서 모든노드들의 최단거리를 담고있음
	vector<int> startMinDistacne = Dijkstra(s, n); // s노드에서 각 노드들까지의 최단거리를 담음
	vector<int> aMinDistacne = Dijkstra(a, n); // a노드에서 각 노드들까지의 최단거리를 담음
	vector<int> bMinDistacne = Dijkstra(b, n); // b노드에서 각 노드들까지의 최단거리를 담음

	// 그 배열들의 합 중 가장 작은 값이 답이다 이말이올시다.
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