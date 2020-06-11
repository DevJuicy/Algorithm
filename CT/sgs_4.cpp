#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N;
vector<vector<char>> terrain;
vector<vector<bool>> visite;

int yDirection[4] = { -1,1,0,0 };
int xDirection[4] = { 0,0,-1,1 };
int reverseDirectionValue[4] = { 2,1,8,4 };
int directionValue[4] = { 1,2,4,8 };
bool change;
vector<pair<int, int>> changeCandidate;

void DEBUG()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << terrain[i][j] << " ";
		}
		cout << endl;
	}
}

int ParseToInt(char c)
{
	return c - '0';
}

bool IsAlphabet(char a)
{
	return a >= 'A' && 'Z' >= a;
}

void InitVisite()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visite[i][j] = false;
		}
	}
}

void SearchSide(int currentY, int currentX)
{
	map<char, int> contryCount;
	for (int i = 0; i < 4; i++)
	{
		int nextY = currentY + yDirection[i];
		int nextX = currentX + xDirection[i];

		if (nextY >= N || nextX >= N || nextY < 0 || nextX < 0)
			continue;

		if (ParseToInt((terrain[currentY][currentX]) & directionValue[i]) > 0)
			continue;

		if (IsAlphabet(terrain[nextY][nextX]))
			contryCount[terrain[nextY][nextX]]++;
	}

	char maxContry = 0;
	int maxCount = 0;
	for (auto it = contryCount.begin(); it != contryCount.end(); it++)
	{
		if (maxCount < it->second)
		{
			maxCount = it->second;
			maxContry = it->first;
		}
		else if (maxCount == it->second)
			return;
	}
	change = true;
	terrain[currentY][currentX] = maxContry;
}

void VisitSide(int currentY, int currentX)
{
	for (int i = 0; i < 4; i++)
	{
		int nextY = currentY + yDirection[i];
		int nextX = currentX + xDirection[i];

		if (nextY >= N || nextX >= N || nextY < 0 || nextX < 0)
			continue;

		if (visite[nextY][nextX])
			continue;

		if (IsAlphabet(terrain[nextY][nextX]))
			continue;

		if (ParseToInt((terrain[nextY][nextX]) & reverseDirectionValue[i]) > 0)
			continue;
		visite[nextY][nextX] = true;
		changeCandidate.push_back({ nextY,nextX });
	}
}

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<char> tempVec;
		for (int j = 0; j < N; j++)
		{
			char temp;
			cin >> temp;
			tempVec.push_back(temp);
		}
		terrain.push_back(tempVec);
	}

	visite.resize(N);
	for (int i = 0; i < N; i++)
		visite[i].resize(N);
}

void Solution()
{
	change = true;
	while (change)
	{
		InitVisite();
		change = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (IsAlphabet(terrain[i][j]))
					VisitSide(i, j);
			}
		}

		for (int i = 0; i < changeCandidate.size(); i++)
		{
			SearchSide(changeCandidate[i].first, changeCandidate[i].second);
		}
		changeCandidate.clear();

		DEBUG();
	}
}

int main()
{
	Input();
	Solution();
}