#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	bool isGame = true;
	vector<string> tempBoard;

	while (isGame)
	{
		isGame = false;
		tempBoard = board;

		// temp벡터에 같은 블록저장
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				char currentCharacter = board[i][j];
				if (board[i][j] == '1')
					continue;

				if (currentCharacter == board[i][j + 1] && currentCharacter == board[i + 1][j] && currentCharacter == board[i + 1][j + 1])
				{
					tempBoard[i][j] = '0';
					tempBoard[i][j + 1] = '0';
					tempBoard[i + 1][j] = '0';
					tempBoard[i + 1][j + 1] = '0';
					isGame = true;
				}
			}
		}

		// 같은블록 1로 변환하여 answer++
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tempBoard[i][j] == '0')
				{
					tempBoard[i][j] = '1';
					answer++;
				}
			}
		}

		// gravity
		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (tempBoard[i][j] == '1')
					continue;

				int h = i;
				char currentCharacter = board[i][j];
				while (tempBoard[h + 1][j] == '1')
				{
					tempBoard[h][j] = '1';
					tempBoard[h + 1][j] = currentCharacter;
					h++;
					if (h >= m - 1)
						break;
				}
			}
		}
		board = tempBoard;
	}

	return answer;
}