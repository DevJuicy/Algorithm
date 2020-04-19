#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;

vector<pair<int, int>> answer;

int Max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void Solution(vector<pair<int, int>> inputs)
{
	sort(inputs.begin(), inputs.end());
	inputs.push_back({ MAX,MAX });

	for (int i = 0; i < inputs.size() - 1; i++)
	{
		if (inputs[i].second < inputs[i + 1].first)
		{
			answer.push_back(inputs[i]);
		}
		else
		{
			inputs[i + 1].first = inputs[i].first;
			inputs[i + 1].second = Max(inputs[i + 1].second, inputs[i].second);
		}
	}
}

int main()
{
	Solution({ {3,6},{1,4},{2,4} });
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].first << " / " << answer[i].second << endl;
	}
}