#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int stagePeople[501];
vector<pair<float, int>> failRate;

bool Compare(pair<float, int> a, pair<float, int> b)
{
	if (a.first == b.first)
		return a.second < b.second; // second 오름차순
	return a.first > b.first; // first 오름차순
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	int peopleCount = stages.size();
	for (int i = 0; i < stages.size(); i++)
	{
		stagePeople[stages[i]]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (stagePeople[i] == 0)
			failRate.push_back({ 0,i });
		else
		{
			failRate.push_back({ (stagePeople[i] / (float)peopleCount),i });
			peopleCount -= stagePeople[i];
		}
	}
	sort(failRate.begin(), failRate.end(), Compare);

	for (int i = 0; i < failRate.size(); i++)
		answer.push_back(failRate[i].second);

	return answer;
}

int main()
{
	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
}