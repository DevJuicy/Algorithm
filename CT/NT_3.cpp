#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(vector<int> b, vector<int> a)
{
	return a[1] / a[0] > b[1] / b[0];
}

int solution(int n, vector<vector<int>> battery)
{
	sort(battery.begin(), battery.end(), Compare);
	int batteryCount = 0;
	int price = 0;
	int minPrice = INT_MAX;
	int index = 0;

	while (index < battery.size())
	{
		if (batteryCount + battery[index][0] < n)
		{
			batteryCount += battery[index][0];
			price += battery[index][1];
		}
		else if (batteryCount + battery[index][0] >= n)
		{
			if (minPrice > price + battery[index][1])
				minPrice = price + battery[index][1];
			index++;
		}
	}

	return minPrice;
}

int main()
{
	cout << solution(50, { {10,100000},{4,35000},{1,15000} }) << endl;
	cout << solution(20, { {6,30000},{3,18000},{4,28000},{1,9500} }) << endl;
}