#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, cnt;
string number;
vector<pair<int, int>> num;
vector<int> answer;

bool Compare(pair<int, int> a, pair<int, int>b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

void Input()
{
	cin >> N >> K;
	cin >> number;
	cnt = N - K;
	for (int i = number.size() - 1; i >= 0; i--)
	{
		num.push_back({ number[i] - 48, number.size() - 1 - i });
	}
	sort(num.begin(), num.end(), Compare);
}

void Solution()
{
	int TOP = num.size() - 1;
	int temp = cnt;

	for (int i = 0; i < temp; i++)
	{
		int index = 0;
		while (true)
		{
			if (num[index].second >= cnt - 1 && num[index].second<TOP)
			{
				answer.push_back(num[index].first);
				TOP = num[index].second;
				cnt--;
				break;
			}
			index++;
		}
	}
}

int main()
{
	Input();
	Solution();
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];
}