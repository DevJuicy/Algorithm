#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> coin;
vector<int> DP;

int Min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

void Input()
{
	cin >> N >> K;

	DP.resize(K + 1);
	for (int i = 0; i < DP.size(); i++)
		DP[i] = 9999999;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
		DP[temp] = 1;
	}
	coin.erase(unique(coin.begin(), coin.end()), coin.end());
}

void Solution()
{
	for (int i = 1; i <= K; i++)
	{
		int temp;
		if (DP[i] == 1)
			continue;
		for (int j = 0; j < coin.size(); j++)
		{
			if (i - coin[j] > 0)
			{
				DP[i] = Min(DP[i - coin[j]] + 1, DP[i]);
			}
		}
	}
	if (DP[K] == 9999999)
		DP[K] = -1;
	cout << DP[K];
}

int main()
{
	Input();
	Solution();
}