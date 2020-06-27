#include <string>
#include <vector>
#include <iostream>
using namespace std;

int yDir[8] = { 1,-1,0,0, 1,-1,1,-1 };
int xDir[8] = { 0,0,1,-1, 1,-1,-1,1 };

int FindNearMine(vector<string>& board, int y, int x)
{
	int mine = 0;
	for (int i = 0; i < 8; i++)
	{
		int nextY = y + yDir[i];
		int nextX = x + xDir[i];

		if (nextY >= board.size() || nextY < 0 || nextX >= board[0].size() || nextX < 0)
			continue;

		if (board[nextY][nextX] == 'M')
			mine++;
	}
	return mine;
}

void DFS(vector<string>& board, int y, int x)
{
	board[y][x] = 'B';

	for (int i = 0; i < 8; i++)
	{
		int nextY = y + yDir[i];
		int nextX = x + xDir[i];

		if (nextY >= board.size() || nextY < 0 || nextX >= board[0].size() || nextX < 0)
			continue;

		if (board[nextY][nextX] != 'E')
			continue;

		int nearMine = FindNearMine(board, nextY, nextX);
		if (nearMine > 0)
		{
			board[nextY][nextX] = nearMine + '0';
		}
		else
		{
			DFS(board, nextY, nextX);
		}
	}
}

vector<string> solution(vector<string> board, int y, int x)
{
	if (board[y][x] == 'M')
	{
		board[y][x] = 'X';
		return board;
	}


	int nearMine = FindNearMine(board, y, x);
	if (nearMine > 0)
	{
		board[y][x] = nearMine + '0';
	}
	else
	{
		DFS(board, y, x);
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 'M')
				board[i][j] = 'E';
		}
	}

	return board;
}

int main()
{
	//solution({
	//	"EEEEE",
	//	"EEMEE",
	//	"EEEEE",
	//	"EEEEE" }, 2, 0);
	solution
	({ "MME","EEE","EME" }, 0, 0);
}