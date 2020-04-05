#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> toiletTime;
int time[151];
int answer = 0;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		toiletTime.push_back({ a,b });
	}
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		int startTime = toiletTime[i].first;
		int endTime = toiletTime[i].second;

		for (int j = startTime; j < endTime; j++)
			time[j]++;
	}

	for (int i = 0; i < 151; i++)
	{
		if (time[i] > answer)
			answer = time[i];
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}