#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int answer;

int PickTopCharacter(vector<vector<int>>& board, int colum)
{
	int ret = -1;

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][colum] == 0)
			continue;

		ret = board[i][colum];
		board[i][colum] = 0;
		return ret;
	}
	return ret;
}

void EraseSameGets()
{
	while (!stk.empty())
	{
		int top = stk.top();
		stk.pop();

		if (stk.empty())
		{
			stk.push(top);
			break;
		}

		if (top == stk.top())
		{
			answer += 2;
			stk.pop();
		}
		else
		{
			stk.push(top);
			break;
		}
	}
}

int solution(vector<vector<int>> board, vector<int> moves)
{
	for (int i = 0; i < moves.size(); i++)
	{
		int get = PickTopCharacter(board, moves[i]-1);

		if (get == -1)
			continue;

		stk.push(get);
		EraseSameGets();
	}
	return answer;
}

int main()
{
	cout << solution
	(
		{
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 3},
		{0, 2, 5, 0, 1},
		{4, 2, 4, 4, 2},
		{3, 5, 1, 3, 1}
		},
		{ 1,5,3,5,1,2,1,4 });
}