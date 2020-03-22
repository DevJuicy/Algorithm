#include <iostream>
#include <vector>

using namespace std;

int N;
char room[101][101];
int row;
int calum;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
			room[i][j] = temp[j];
	}
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		int current = 0;
		for (int j = 0; j < N; j++)
		{
			if (room[i][j] == '.')
				current++;
			if (room[i][j] == 'X' || j==N-1)
			{
				if (current > 1)
					row++;
				current = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		int current = 0;
		for (int j = 0; j < N; j++)
		{
			if (room[j][i] == '.')
				current++;
			if (room[j][i] == 'X' || j == N - 1)
			{
				if (current > 1)
					calum++;
				current = 0;
			}
		}
	}
}

int main()
{
	Input();
	Solution();
	cout << row << " " << calum;
}