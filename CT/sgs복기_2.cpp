#include <iostream>
#include <vector>

using namespace std;

int N;
int W;
vector<vector<string>> names;

void DEBUG()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << names[i][j] << " ";
		}
		cout << endl;
	}
}

void Move(int size, string& nextName, int& y, int& x, string& currentName, int& pos, int weight)
{
	for (int i = 0; i < size; i++)
	{
		pos += weight;
		nextName = names[y][x];
		names[y][x] = currentName;
		currentName = nextName;
	}
}

void ReverseRoateNames(int R, int start)
{
	for (int i = 0; i < R; i++)
	{
		int y = start;
		int x = start;
		int size = N - start * 2 - 1;
		string currentName = names[y][x];
		string nextName;

		Move(size, nextName, y, x, currentName, y, 1);
		Move(size, nextName, y, x, currentName, x, 1);
		Move(size, nextName, y, x, currentName, y, -1);
		Move(size, nextName, y, x, currentName, x, -1);
	}
}

void RotateNames(int R, int start)
{
	for (int i = 0; i < R; i++)
	{
		int y = start;
		int x = start;
		int size = N - start * 2 - 1;
		string currentName = names[y][x];
		string nextName;

		Move(size, nextName, y, x, currentName, x, 1);
		Move(size, nextName, y, x, currentName, y, 1);
		Move(size, nextName, y, x, currentName, x, -1);
		Move(size, nextName, y, x, currentName, y, -1);
	}
}

void Input()
{
	cin >> N >> W;
	for (int i = 0; i < N; i++)
	{
		vector<string> tempVec;
		for (int j = 0; j < N; j++)
		{
			string temp;
			cin >> temp;
			tempVec.push_back(temp);
		}
		names.push_back(tempVec);
	}
}

void Solution()
{
	for (int i = 0; i < N / 2; i++)
	{
		int weight = W % (((N - i * 2) - 1)  * 4);

		if (i % 2 == 1)
			weight *= -1;

		if (weight > 0)
			RotateNames(weight, i);
		else
			ReverseRoateNames(weight * -1, i);
	}
}

int main()
{
	Input();
	Solution();
	DEBUG();

}