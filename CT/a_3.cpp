#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> price;
vector<int> candidate;
queue<int> priceQ;

int Solution(int n, vector<vector<int>> battery)
{
	int currentCount = 0;
	int answer = 0;
	for (int i = 0; i < battery.size(); i++)
	{
		price.push_back({ battery[i][1] / battery[i][0],i });
	}
	sort(price.begin(), price.end());

	for (int i = 0; i < price.size(); i++)
		priceQ.push(price[i].second);

	while (!priceQ.empty())
	{
		if (battery[priceQ.front()][0] <= n - currentCount)
		{
			currentCount += battery[priceQ.front()][0];
			answer += battery[priceQ.front()][1];
			if (n == currentCount)
			{
				candidate.push_back(answer);
				priceQ.pop();
			}
		}
		else
		{
			candidate.push_back(answer + battery[priceQ.front()][1]);
			priceQ.pop();
		}
	}

	answer = candidate[0];
	for (int i = 1; i < candidate.size(); i++)
	{
		if (answer > candidate[i])
			answer = candidate[i];
	}
	return answer;
}

int main()
{
	//cout << Solution(50, { {10,100000},{4,35000},{1,15000} });
	cout << Solution(20, { {6,30000},{3,18000},{4,28000},{1,9500} });
}