#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> nodes(51);
int deleteNumber;
int rootNumber;
int answer;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			rootNumber = i;
		else
			nodes[temp].push_back(i);
	}
	cin >> deleteNumber;
}

void DeleteNode()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes[i].size(); j++)
		{
			if (nodes[i][j] == deleteNumber)
				nodes[i].erase(nodes[i].begin() + j);
		}
	}
}

void DFS(int index)
{
	if (nodes[index].size() == 0)
		answer++;

	for (int i = 0; i < nodes[index].size(); i++)
	{
		DFS(nodes[index][i]);
	}
}

void Solution()
{
	DeleteNode();
	if (deleteNumber == rootNumber)
		answer = 0;
	else
		DFS(rootNumber);
}

int main()
{
	Input();
	Solution();
	cout << answer;
}