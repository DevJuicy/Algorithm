#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int days;
vector<int> prices;
priority_queue<pair<int, int>> prioryPrices;

void Input()
{
	cin >> days;
	for (int i = 0; i < days; i++)
	{
		int temp;
		cin >> temp;
		prices.push_back(temp);
		prioryPrices.push({ temp,i });
	}
}

void Solution()
{
	int money = 0;
	int coinCount = 0;

	int currentIndex = 0;
	int maxIndex = prioryPrices.top().second;

	while (maxIndex > currentIndex)
	{
		for (; currentIndex < maxIndex; currentIndex++)
		{
			money -= prices[currentIndex];
			coinCount++;
		}

		money += coinCount * prices[maxIndex];
		money--;
		currentIndex++;
		coinCount = 0;

		prioryPrices.pop();
		maxIndex = prioryPrices.top().second;
	}
	cout << money;
}

int main()
{
	Input();
	Solution();
}