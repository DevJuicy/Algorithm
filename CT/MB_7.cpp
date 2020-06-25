#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Position
{
public:
	int y;
	int x;
	int dist;
	Position(int y, int x, int dist)
	{
		this->y = y;
		this->x = x;
		this->dist = dist;
	}
};

int yDir[4] = { 1,-1,0,0 };
int xDir[4] = { 0,0,-1,1 };

vector<vector<int>> dist;

Position FindMinPosition(vector<Position>& vec)
{
	Position ret(-1, -1, 101);
	int minIndex = -1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].dist <= ret.dist)
		{
			minIndex = i;
			ret.y = vec[i].y;
			ret.x = vec[i].x;
			ret.dist = vec[i].dist;
		}
	}

	vec.erase(vec.begin() + minIndex);
	return ret;
}

int solution(vector<vector<int>> board, int c)
{
	int ySize = board.size();
	int xSize = board[0].size();

	vector<Position> minPositions;
	int startY, startX, endY, endX;


	for (int i = 0; i < board.size(); i++)
	{
		vector<int> temp;
		temp.resize(board[i].size());
		dist.push_back(temp);

		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 2)
			{
				startY = i;
				startX = j;
			}
			else if (board[i][j] == 3)
			{
				endY = i;
				endX = j;
				dist[i][j] = 10000;
			}
			else
			{
				dist[i][j] = 10000;
			}
		}
	}

	minPositions.push_back(Position(startY, startX, 0));

	while (true)
	{
		Position minPos = FindMinPosition(minPositions);
		if (minPos.y == endY && minPos.x == endX)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nextY = minPos.y + yDir[i];
			int nextX = minPos.x + xDir[i];

			if (nextY < 0 || nextY >= ySize || nextX < 0 || nextX >= xSize)
				continue;

			int weight = minPos.dist + 1;
			if (board[nextY][nextX] == 1)
				weight += c;

			if (dist[nextY][nextX] > weight)
			{
				dist[nextY][nextX] = weight;
				minPositions.push_back(Position(nextY, nextX, weight));
			}
		}
	}


	for (int i = 0; i < ySize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			if (dist[i][j] == 10000)
				cout << "X      ";
			else
				cout << dist[i][j] << "      ";
		}
		cout << endl << endl;
	}
	return dist[endY][endX];
}

int main()
{
	cout << solution(
		{
			{0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
			{0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
			{0, 0, 0, 0, 3, 0, 0, 0, 1, 0}
		}, 2);
}