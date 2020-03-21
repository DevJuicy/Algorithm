#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> color(1001);
vector<vector<int>> DP(1001,vector<int>(3,0));
int answer;

int Min(int a, int b)
{
	if (a > b) return b;
	else return a;
}

void Input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;
			color[i].push_back(temp);
		}
	}
}

void Solution()
{
	DP[1][0] = color[1][0];
	DP[1][1] = color[1][1];
	DP[1][2] = color[1][2];

	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = Min(DP[i - 1][1], DP[i - 1][2]) + color[i][0];
		DP[i][1] = Min(DP[i - 1][0], DP[i - 1][2]) + color[i][1];
		DP[i][2] = Min(DP[i - 1][0], DP[i - 1][1]) + color[i][2];
	}
	
	answer = Min(DP[N][0], Min(DP[N][1], DP[N][2]));
}

int main()
{
	Input();
	Solution();
	cout << answer;
}