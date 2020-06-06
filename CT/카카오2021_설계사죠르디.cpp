#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Position
{
public:
	int y, x;
	Position(int y, int x)
	{
		this->y = y;
		this->x = x;
	}
};

int axis_y[4] = { -1,0,1,0 };
int axis_x[4] = { 0,1,0,-1 };

enum Direction
{
	UP, RIGHT, DOWN, LEFT
};

void DEBUG(vector<vector<int>>& board)
{
	cout << endl;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void InitBoardValue(vector<vector<int>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] != 1)
				board[i][j] = 0;
		}
	}
	board[0][0] = 100;
}

void DFS(Position currentPosition, Direction currentDirect, vector<vector<int>>& board, int cost)
{
	for (int i = 0; i < 4; i++)
	{
		int nextY = currentPosition.y + axis_y[i];
		int nextX = currentPosition.x + axis_x[i];

		if (nextY < 0 || nextX < 0 || nextY >= board.size() || nextX >= board.size())
			continue;

		if (board[nextY][nextX] == 1)
			continue;

		int currentCost = cost;
		if (i == currentDirect)
			currentCost += 100;
		else
			currentCost += 600;

		if (board[nextY][nextX] == 0 || board[nextY][nextX] > currentCost)
			board[nextY][nextX] = currentCost;
		else
			continue;

		DFS(Position(nextY, nextX), (Direction)i, board, currentCost);
	}
}

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int rightCost, downCost;

	InitBoardValue(board);
	DFS(Position(0, 0), RIGHT, board, 0);
	rightCost = board[board.size() - 1][board.size() - 1];
	//DEBUG(board);

	InitBoardValue(board);
	DFS(Position(0, 0), DOWN, board, 0);
	downCost = board[board.size() - 1][board.size() - 1];
	//DEBUG(board);

	if (rightCost < downCost)
		answer = rightCost;
	else
		answer = downCost;

	return answer;
}

int main()
{
	cout << solution({
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0} }
	) << endl;

	cout << solution(
		{ {0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0} }) << endl;

	cout << solution(
		{ {0, 0, 1, 0},
		{0, 0, 0, 0},
		{0, 1, 0, 1},
		{1, 0, 0, 0} }
	) << endl;

	cout << solution(
		{ {0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 0},
		{0, 0, 1, 0, 0, 0},
		{1, 0, 0, 1, 0, 1},
		{0, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0} }
	) << endl;
}