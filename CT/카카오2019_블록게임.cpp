#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Block
{
public:
	int index;
	int* blockAddress[6];

	Block(int index, int* add0, int* add1, int* add2, int* add3, int* add4, int* add5)
	{
		this->index = index;
		blockAddress[0] = add0;
		blockAddress[1] = add1;
		blockAddress[2] = add2;
		blockAddress[3] = add3;
		blockAddress[4] = add4;
		blockAddress[5] = add5;
	}
};

vector<Block> candidatie;

void FindBlock(int& add0, int& add1, int& add2, int& add3, int& add4, int& add5)
{
	vector<int> indexList;
	indexList.push_back(add0);
	indexList.push_back(add1);
	indexList.push_back(add2);
	indexList.push_back(add3);
	indexList.push_back(add4);
	indexList.push_back(add5);
	sort(indexList.begin(), indexList.end());

	int current = 0;
	int cnt = 0;

	for (int i = 0; i < 6; i++)
	{
		if (indexList[i] == 0)
			continue;

		if (current == indexList[i])
			cnt++;
		else
		{
			current = indexList[i];
			cnt = 1;
		}

		if (cnt == 4)
			break;
	}
	if (cnt == 4)
		candidatie.push_back(Block(current, &add0, &add1, &add2, &add3, &add4, &add5));
}

int solution(vector<vector<int>> board)
{
	int answer = 0;

	// find row
	for (int i = 0; i < board.size() - 1; i++)
	{
		for (int j = 0; j < board[i].size() - 2; j++)
		{
			FindBlock(board[i][j], board[i][j + 1], board[i][j + 2], board[i + 1][j], board[i + 1][j + 1], board[i + 1][j + 2]);
		}
	}

	// find colum
	for (int i = 0; i < board.size() - 2; i++)
	{
		for (int j = 0; j < board[i].size() - 1; j++)
		{
			FindBlock(board[i][j], board[i][j + 1], board[i + 1][j], board[i + 1][j + 1], board[i + 2][j], board[i + 2][j + 1]);
		}
	}

	while (true)
	{
		// 블록채우기
		for (int i = 0; i < board[0].size(); i++)
		{
			for (int j = 0; j < board.size(); j++)
			{
				if (board[j][i] == -1)
					continue;
				else if (board[j][i] == 0)
					board[j][i] = -1;
				else
					break;
			}
		}

		bool continueWhile = false;

		// 삭제시키기
		for (int i = 0; i < candidatie.size(); i++)
		{
			bool removable = true;
			for (int j = 0; j < 6; j++)
			{
				if (*candidatie[i].blockAddress[j] != -1 && *candidatie[i].blockAddress[j] != candidatie[i].index)
				{
					removable = false;
					break;
				}
			}

			if (removable)
			{
				answer++;
				continueWhile = true;
				for (int j = 0; j < 6; j++)
				{
					if (*candidatie[i].blockAddress[j] == candidatie[i].index)
						*candidatie[i].blockAddress[j] = 0;
				}
				candidatie.erase(candidatie.begin() + i);
			}
		}

		// 디버그용
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == -1)
					cout << "*" << " ";
				else
					cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		if (!continueWhile)
			break;
	}


	return answer;
}

int main()
{
	//solution({
	//	{0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,4,0,0,0},
	//	{0,0,0,0,0,4,4,0,0,0},
	//	{0,0,0,0,3,0,4,0,0,0},
	//	{0,0,0,2,3,0,0,0,5,5},
	//	{1,2,2,2,3,3,0,0,0,5},
	//	{1,1,1,0,0,0,0,0,0,5}
	//	});
	cout << solution(
		{
		 {0,0,0,0,0,0,0,0,0,0}
		,{0,0,0,0,0,0,0,0,0,0}
		,{0,0,0,0,0,0,0,0,0,0}
		,{0,0,0,0,0,0,0,0,0,0}
		,{0,0,0,2,2,0,0,0,0,0}
		,{0,0,0,2,1,0,0,0,0,0}
		,{0,0,0,2,1,0,0,0,0,0}
		,{0,0,0,0,1,1,0,0,0,0}
		,{0,0,0,0,0,0,0,0,0,0}
		,{0,0,0,0,0,0,0,0,0,0}
		}
	);
}