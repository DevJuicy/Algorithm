#include <iostream>
#include <vector>

using namespace std;

int N;
int DP[1000001];

int Min(int a, int b)
{
	if (a > b) return b;
	else return a;
}

void Input()
{
	cin >> N;
}

void Solution()
{
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)
			DP[i] = Min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)
			DP[i] = Min(DP[i], DP[i / 3] + 1);
	}
}

int main()
{
	Input();
	Solution();
	cout << DP[N];
}