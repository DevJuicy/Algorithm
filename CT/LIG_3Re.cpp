#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> zero;
int DP[300001];

int solution(string road, int n)
{
	int answer = 1;

	for (int i = 0; i < road.size(); i++)
	{
		if (road[i] == '0')
			zero.push_back(i);
	}

	int remainCount = n;
	int zeroIndex = 0;

	DP[0] = 1;

	for (int i = 1; i < road.size(); i++)
	{
		if (road[i] == '1') // 1
		{
			DP[i] = DP[i - 1] + 1;
		}
		else // 0
		{
			if (remainCount > 0) // 재료가 남은경우
			{
				DP[i] = DP[i - 1] + 1;
				remainCount--;
			}
			else
			{
				DP[i] = i - DP[zero[zeroIndex]];
				zeroIndex++;
			}
		}
		answer = max(answer, DP[i]);
	}
	return answer;
}

int main()
{
	cout << solution("0", 3);
}
