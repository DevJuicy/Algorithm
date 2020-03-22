#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> computer;
vector<bool> visited;
vector<int> answer;
int maxValue;
int currentValue;

void Input()
{
	cin >> N >> M;
	computer.resize(N+1);
	visited.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int parent, child;
		cin >> child >> parent;
		computer[parent].push_back(child);
	}
}

void DFS(int i)
{
	visited[i] = true;
	currentValue++;
	for (int j = 0; j < computer[i].size(); j++)
	{
		if(!visited[computer[i][j]])
			DFS(computer[i][j]);
	}
}

void InitVisit()
{
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		currentValue = 0;
		InitVisit();
		DFS(i);
		answer.push_back(currentValue);
		if (currentValue >= maxValue)
			maxValue = currentValue;
	}
	for (int i = 0; i < N; i++)
	{
		if (answer[i] == maxValue)
			cout << i + 1 << " ";
	}
}

int main()
{
	Input();
	Solution();
}