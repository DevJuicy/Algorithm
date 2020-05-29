#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(vector<int> b, vector<int> a)
{
	return (float)b[1] / b[0] < (float)a[1] / a[0];
}

int solution(int n, vector<vector<int>> battery)
{
	int answer = INT_MAX;

	int count = 0;
	sort(battery.begin(), battery.end(), Compare);

	int currentIndex = 0;
	int currentValue = 0;

	while (true)
	{
		if (count + battery[currentIndex][0] >= n)
		{
			answer = min(answer, currentValue + battery[currentIndex][1]);
			currentIndex++;
		}
		else
		{
			count += battery[currentIndex][0];
			currentValue += battery[currentIndex][1];
		}
		
		if (currentIndex >= battery.size())
			break;
	}


	return answer;
}

int main()
{
	//cout << solution(50, { {10,100000},{4,35000},{1,15000} });
	cout << solution(20, { {6,30000},{3,18000},{4,28000},{1,9500} });
}