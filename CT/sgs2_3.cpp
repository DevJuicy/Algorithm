#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<char>> map;
vector<vector<bool>> visited;

int currentSize;
int yDir[4] = { -1,1,0,0 };
int xDir[4] = { 0,0,-1,1 };

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<char> tempVec;
		vector<bool> tempVisited;
		tempVisited.resize(N);
		for (int i = 0; i < N; i++)
		{
			char temp;
			cin >> temp;
			tempVec.push_back(temp);
		}
		map.push_back(tempVec);
		visited.push_back(tempVisited);
	}
}

void DFS(int y, int x)
{
	int nextY, nextX;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		nextY = y + yDir[i];
		nextX = x + xDir[i];

		if (nextY >= N || nextX >= N || nextY < 0 || nextX < 0)
			continue;
		
		if (visited[nextY][nextX])
			continue;

		if (map[nextY][nextX] == 'W')
			continue;

		currentSize++;
		DFS(nextY, nextX);
	}
}

float GetAverage(vector<int>& vec)
{
	float sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i];
	}

	return sum / vec.size();
}

float GetMidValue(vector<int>& vec)
{
	if (vec.size() % 2 == 1)
	{
		return vec[vec.size() / 2];
	}
	else
	{
		return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2;
	}
}

void Solution()
{
	vector<int> groundSize;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'W' || visited[i][j])
				continue;

			currentSize = 1;
			DFS(i, j);
			groundSize.push_back(currentSize);
		}
	}

	sort(groundSize.begin(), groundSize.end(), greater<int>());
	
	if (groundSize.size() == 0)
	{
		cout << "0 0 0.00 0";
		return;
	}

	int continentSize = groundSize[0];
	vector<int> islandSize;
	for (int i = 0; i < groundSize.size(); i++)
	{
		if (groundSize[i] == continentSize)
			continue;

		islandSize.push_back(groundSize[i]);
	}
	
	if (islandSize.size() == 0)
	{
		cout << "0 0 0.00 0";
		return;
	}

	int maxIslandSize = islandSize[0];
	int minIslnadSize = islandSize[islandSize.size() - 1];
	float aveIslandSize = GetAverage(islandSize);
	float midIslandSize = GetMidValue(islandSize);

	cout.precision(3);
	cout << maxIslandSize << " " << minIslnadSize << " " << aveIslandSize << " " << midIslandSize;
}

int main()
{
	Input();
	Solution();
}