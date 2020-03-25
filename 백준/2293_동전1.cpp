#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> coin;
vector<int> DP;

void Input()
{
	cin >> N >> K;
	DP.resize(K + 1);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		DP[coin[i]]++;
		for (int j = coin[i] + 1; j <= K; j++)
		{
			DP[j] += DP[j - coin[i]];
		}
	}
	cout << DP[K];
}

int main()
{
	Input();
	Solution();
}