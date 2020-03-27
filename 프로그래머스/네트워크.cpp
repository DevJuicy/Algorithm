#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> com;
vector<bool> visited;

void DFS(int index)
{
	visited[index] = true;
	for (int i = 0; i < com[index].size(); i++)
	{
		if (!visited[com[index][i]])
			DFS(com[index][i]);
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	com.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || computers[i][j] == 0)
				continue;
			com[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			answer++;
		}
	}
	return answer;
}

int main()
{
	//cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} }) << endl;
	cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} });
}