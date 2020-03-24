#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> people;
long long sum;
int answer;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int pos, num;
		cin >> pos >> num;
		people.push_back({ pos,num });
		sum += num;
	}
	sort(people.begin(), people.end());
}

void Solution()
{
	long long left = 0;
	long long right = sum;
	for (int i = 0; i < N; i++)
	{
		left += people[i].second;
		right -= people[i].second;
		if (left >= right)
		{
			answer = people[i].first;
			break;
		}
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}