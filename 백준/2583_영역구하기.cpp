#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int mv_x[4] = { 1,-1,0,0 };
const int mv_y[4] = { 0,0,1,-1 };

int N, M, K;
int map[101][101];
bool visited[101][101];

queue<pair<int, int>> Q;

vector<int> answer;
int sum;

void BFS(int currentY, int currentX)
{
	sum++;
	visited[currentY][currentX] = true;
	Q.push({ currentY,currentX });
	while (!Q.empty())
	{
		currentY = Q.front().first;
		currentX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (currentY + mv_y[i] >= N || currentY + mv_y[i] < 0
				|| currentX + mv_x[i] >= M || currentX + mv_x[i] < 0)
				continue;

			int nextY = currentY + mv_y[i];
			int nextX = currentX + mv_x[i];

			if (map[nextY][nextX] == 1 || visited[nextY][nextX])
				continue;

			sum++;
			visited[nextY][nextX] = true;
			Q.push({ nextY, nextX });
		}
	}
}

void DFS(int currentY, int currentX)
{
	visited[currentY][currentX] = true;
	sum++;
	for (int i = 0; i < 4; i++)
	{
		if (currentY + mv_y[i] >= N || currentY + mv_y[i] < 0
			|| currentX + mv_x[i] >= M || currentX + mv_x[i] < 0)
			continue;

		int nextY = currentY + mv_y[i];
		int nextX = currentX + mv_x[i];

		if (map[nextY][nextX] == 1 || visited[nextY][nextX])
			continue;

		DFS(nextY, nextX);
	}
}

void Input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				map[i][j] = 1;
			}
		}
	}
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 || visited[i][j])
				continue;
			sum = 0;
			//DFS(i, j);
			BFS(i, j);
			answer.push_back(sum);
		}
	}
}

int main()
{
	Input();
	Solution();
	cout << answer.size() << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}