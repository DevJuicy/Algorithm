#include <string>
#include <iostream>
#include <vector>
#define MAXMAP 7

using namespace std;
int map[MAXMAP][MAXMAP];
bool visited[MAXMAP][MAXMAP];
int yAxis[] = { 1,0,-1,0 };
int xAxis[] = { 0,1,0,-1 };
int sameColor;
vector<pair<int, int>> positionBuffer;

void DEBUG()
{
	for (int i = 1; i < MAXMAP; i++)
	{
		for (int j = 1; j < MAXMAP; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void InitVisited()
{
	for (int i = 1; i < MAXMAP; i++)
	{
		for (int j = 1; j < MAXMAP; j++)
		{
			visited[i][j] = false;
		}
	}
}

int FindHeight(int i)
{
	for (int height = 1; height < MAXMAP; height++)
	{
		if (map[height][i] == 0)
		{
			return height;
		}
	}
	return -1; // 이 경우는 주어지지 않음
}

void ApplyGravity()
{
	for (int i = 2; i < MAXMAP; i++)
	{
		for (int j = 1; j < MAXMAP; j++)
		{
			if (map[i][j] == 0)
				continue;

			int currentY = i;

			while (true)
			{
				if (map[currentY - 1][j] != 0 || currentY - 1 <= 0)
					break;

				map[currentY - 1][j] = map[currentY][j];
				map[currentY][j] = 0;
				currentY--;
			}
		}
	}
}

void RemoveColor()
{
	for (int i = 0; i < positionBuffer.size(); i++)
	{
		map[positionBuffer[i].first][positionBuffer[i].second] = 0;
	}
}

void DFS(int y, int x)
{
	positionBuffer.push_back({ y,x });
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + yAxis[i];
		int nextX = x + xAxis[i];

		if (nextY >= MAXMAP || nextX >= MAXMAP || nextY <= 0 || nextX <= 0)
			continue;
		if (visited[nextY][nextX])
			continue;

		if (map[nextY][nextX] == map[y][x])
		{
			sameColor++;
			DFS(nextY, nextX);
		}
	}
}

void StartDFS()
{
	InitVisited();
	for (int i = 1; i < MAXMAP; i++)
	{
		for (int j = 1; j < MAXMAP; j++)
		{
			if (visited[i][j] || map[i][j] == 0)
				continue;

			sameColor = 1;
			positionBuffer.clear();
			DFS(i, j);

			if (sameColor >= 3) // 같은게 3개 이상인경우
			{
				// 삭제
				RemoveColor();
				// 중력
				ApplyGravity();
				// 방문 초기화
				InitVisited();
				// 인덱스 초기화
				i = 0;
				j = 0;
			}
		}
	}
}

vector<string> solution(vector<vector<int>> macaron)
{
	vector<string> answer;

	for (int i = 0; i < macaron.size(); i++)
	{
		int xPosition = macaron[i][0];
		int color = macaron[i][1];

		map[FindHeight(xPosition)][xPosition] = color;
		StartDFS();
	}


	for (int i = MAXMAP - 1; i >= 1; i--)
	{
		string temp = "";
		for (int j = 1; j < MAXMAP; j++)
		{
			temp += to_string(map[i][j]);
		}
		answer.push_back(temp);
	}
	return answer;
}

int main()
{
	solution({ {1, 1}, {2, 1}, {1, 2}, {3, 3}, {6, 4}, {3, 1}, {3, 3},{3, 3},
	{3, 4}, {2, 1} });
	solution({ {1,1},{1,2},{1,4},{2,1},{2,2},{2,3},{3,4},{3,1},{3,2},{3,3},
	{3,4},{4,4},{4,3},{5,4},{6,1} });
}