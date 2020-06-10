#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int N, D;
vector<vector<string>> names;

void Input()
{
	cin >> N >> D;
	names.resize(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			string temp;
			cin >> temp;
			names[i].push_back(temp);
		}
	}
}

void ReversSpin(int n, int direction)
{
	for (int d = 0; d < direction; d++)
	{
		string current = names[n][n];
		string next;
		int y = n;
		int x = n;

		for (int i = 1; i < N - 2 * n; i++)
		{
			y++;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
		for (int i = 1; i < N - 2 * n; i++)
		{
			x++;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
		for (int i = 1; i < N - 2 * n; i++)
		{
			y--;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
		for (int i = 1; i < N - 2 * n; i++)
		{
			x--;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
	}
}


void Spin(int n, int direction)
{
	for (int d = 0; d < direction; d++)
	{
		string current = names[n][n];
		string next;
		int y = n;
		int x = n;
		for (int i = 1; i < N - 2 * n; i++)
		{
			x++;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
		for (int i = 1; i < N - 2 * n; i++)
		{
			y++;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
		for (int i = 1; i < N - 2 * n; i++)
		{
			x--;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
		for (int i = 1; i < N - 2 * n; i++)
		{
			y--;
			next = names[y][x];
			names[y][x] = current;
			current = next;
		}
	}
}

void Solution()
{
	for (int i = 0; i < N / 2; i++)
	{
		int interval = (N - i * 2 - 1) * 4;
		if (interval == 0)
			break;
		int direction = D % interval;

		if (i % 2 == 1)
			direction *= -1;


		if (direction > 0)
			Spin(i, direction);
		else
			ReversSpin(i, direction * -1);


	}
}

int main()
{
	Input();
	Solution();

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