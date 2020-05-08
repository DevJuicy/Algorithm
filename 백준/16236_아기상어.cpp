// DFS는 최단거리가 안나올 수 도 있다
// 거의 모든 노드를 탐색해야할 수 도 있다

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50
using namespace std;

class Position
{
public:
	int y;
	int x;
	int depth;
	Position(int y, int x, int depth)
	{
		this->y = y;
		this->x = x;
		this->depth = depth;
	}
};

class Fish
{
public:
	int yPosition;
	int xPosition;
	int distance = MAX;
	Fish(int y, int x)
	{
		yPosition = y;
		xPosition = x;
	}
};

int N;
int map[21][21];
bool visited[21][21];

int level = 2;
int eatCount = 0;
int yShark;
int xShark;

int yAxis[4] = { 1,0,-1,0 };
int xAxis[4] = { 0,1,0,-1 };
queue<Position> positionQ;

void DEBUG()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				yShark = i;
				xShark = j;
				map[i][j] = 0;
			}
		}
	}
}

void InitSearch()
{
	while (!positionQ.empty())
		positionQ.pop();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
	}
}

bool Compare(Fish a, Fish b)
{
	if (a.distance == b.distance)
	{
		if (a.yPosition == b.yPosition)
			return a.xPosition < b.xPosition;
		else
			return a.yPosition < b.yPosition;
	}
	return a.distance < b.distance;
}

void UpLevel()
{
	if (eatCount >= level)
	{
		eatCount = 0;
		level++;
	}
}

int BFS(int destinationY, int destinationX)
{
	while (!positionQ.empty())
	{
		int currentY = positionQ.front().y;
		int currentX = positionQ.front().x;
		int depth = positionQ.front().depth;
		visited[currentY][currentX] = true;
		positionQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = currentY + yAxis[i];
			int nextX = currentX + xAxis[i];

			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (map[nextY][nextX] > level)
				continue;

			if (nextY == destinationY && nextX == destinationX)
				return depth + 1;

			visited[nextY][nextX] = true;
			positionQ.push(Position(nextY, nextX, depth + 1));
		}
	}
	return MAX;
}

int GetDistance(Fish fish)
{
	int distance = 0;
	positionQ.push(Position(yShark, xShark, 0));
	return BFS(fish.yPosition, fish.xPosition);
}

vector<Fish> FindSmallFish()
{
	vector<Fish> smallFishes;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] <= 0)
				continue;

			if (map[i][j] < level)
				smallFishes.push_back(Fish(i, j));
		}
	}
	return smallFishes;
}

int Solution()
{
	int answer = 0;

	while (true)
	{
		vector<Fish> smallFishes = FindSmallFish();
		if (smallFishes.size() == 0)
			break;

		for (int i = 0; i < smallFishes.size(); i++)
		{
			InitSearch();
			smallFishes[i].distance = GetDistance(smallFishes[i]);
		}

		sort(smallFishes.begin(), smallFishes.end(), Compare);
		if (smallFishes[0].distance == MAX)
			break;

		map[smallFishes[0].yPosition][smallFishes[0].xPosition] = 0;
		eatCount++;
		UpLevel();

		yShark = smallFishes[0].yPosition;
		xShark = smallFishes[0].xPosition;

		answer += smallFishes[0].distance;
		//DEBUG();
	}

	return answer;
}


int main()
{
	Input();
	cout << Solution();
}