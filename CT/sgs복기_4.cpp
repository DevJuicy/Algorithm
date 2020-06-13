#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Ground
{
public:
	int y;
	int x;
	char c;
	Ground(int y, int x, char c)
	{
		this->y = y;
		this->x = x;
		this->c = c;
	}
};

int N;
bool isChanged;
vector<vector<char>> terrain;
vector<vector<bool>> visitied;
vector<Ground> groundCandidate;

// 상하좌우
int yDirection[] = { -1,1,0,0 };
int xDirection[] = { 0,0,-1,1 };
int valueDirection[] = { 1,2,4,8 };
int RvalueDirection[] = { 2,1,8,4 };

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

void InitVistiedArray()
{
	for (int i = 0; i < visitied.size(); i++)
	{
		for (int j = 0; j < visitied.size(); j++)
			visitied[i][j] = false;
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

		vector<bool> tempVisted;
		tempVisted.resize(N);
		visitied.push_back(tempVisted);
	}
}

bool IsCharacter(char c)
{
	return c >= 'A' && c <= 'Z';
}

char FindMaxMapValue(map<char, int>& m, int weight)
{
	vector<char> ret;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second == weight)
		{
			ret.push_back(it->first);
		}
	}
	if (ret.size() == 1)
		return ret[0];
	else
		return '0';
}

void ChangeGround(Ground ground)
{
	terrain[ground.y][ground.x] = ground.c;
}

void SearchGround(Ground& ground)
{
	map<char, int> nearContryCount;

	int nextY, nextX;
	for (int i = 0; i < 4; i++)
	{
		nextY = ground.y + yDirection[i];
		nextX = ground.x + xDirection[i];

		if (nextY >= N || nextX >= N || nextY < 0 || nextX < 0)
			continue;

		if (!IsCharacter(terrain[nextY][nextX]))
			continue;

		if ((valueDirection[i] & ParseToInt(terrain[ground.y][ground.x])) > 0)
			continue;

		nearContryCount[terrain[nextY][nextX]]++;
	}

	if (FindMaxMapValue(nearContryCount, 3) != '0') // 맥스가 3인경우
	{
		ground.c = FindMaxMapValue(nearContryCount, 3);
		isChanged = true;
	}
	else if (FindMaxMapValue(nearContryCount, 2) != '0') // 맥스가 2인경우
	{
		ground.c = FindMaxMapValue(nearContryCount, 2);
		isChanged = true;
	}
	else if (FindMaxMapValue(nearContryCount, 1) != '0') // 맥스가 1인경우
	{
		ground.c = FindMaxMapValue(nearContryCount, 1);
		isChanged = true;
	}
}

void FindNearGround(int y, int x)
{
	int nextY, nextX;
	for (int i = 0; i < 4; i++)
	{
		nextY = y + yDirection[i];
		nextX = x + xDirection[i];

		if (nextY >= N || nextX >= N || nextY < 0 || nextX < 0)
			continue;

		if (visitied[nextY][nextX])
			continue;

		if (IsCharacter(terrain[nextY][nextX]))
			continue;

		if ((RvalueDirection[i] & ParseToInt(terrain[nextY][nextX])) > 0)
			continue;

		visitied[nextY][nextX] = true;
		groundCandidate.push_back(Ground(nextY, nextX, terrain[nextY][nextX]));
	}
}

void Solution()
{
	int answer = -1;
	isChanged = true;
	while (isChanged)
	{
		answer++;
		isChanged = false;
		InitVistiedArray();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (IsCharacter(terrain[i][j]))
					FindNearGround(i, j);
			}
		}

		for (int i = 0; i < groundCandidate.size(); i++)
		{
			SearchGround(groundCandidate[i]);
		}

		for (int i = 0; i < groundCandidate.size(); i++)
		{
			ChangeGround(groundCandidate[i]);
		}
		groundCandidate.clear();
	}
	cout << answer;
	DEBUG();
}

int main()
{
	Input();
	Solution();
}