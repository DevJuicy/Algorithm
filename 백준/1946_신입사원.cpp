#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
vector<int> answer;
vector<pair<int, int>> people;

void Sort()
{
	sort(people.begin(), people.end());
}

void Solution()
{
	Sort();
	int ans = 1;
	int suc = people[0].second;
	for (int i = 1; i < people.size(); i++)
	{
		if (people[i].second < suc)
		{
			suc = people[i].second;
			ans++;
		}
	}
	answer.push_back(ans);
}

void Input()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		people.clear();
		int N;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			int first, second;
			cin >> first >> second;
			people.push_back({ first,second });
		}
		Solution();
	}
}

int main()
{
	Input();
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}