#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
using namespace std;

map<string, deque<int>> m;

vector<int> solution(vector<string> gems)
{
	vector<int> answer;
	int interval = 100000;
	int candidateStart;
	int candidateEnd;

	for (int i = 0; i < gems.size(); i++)
	{
		if (m.find(gems[i]) == m.end())
		{
			deque<int> q;
			q.push_back(i + 1);
			m[gems[i]] = q;
		}
		else
		{
			m[gems[i]].push_back(i + 1);
		}
	}

	if (m.size() == 1)
	{
		answer.push_back(1);
		answer.push_back(1);
		return answer;
	}


	while (true)
	{
		int start = 100000;
		int end = 0;

		string startString = "";
		string endString = "";

		for (auto it = m.begin(); it != m.end(); it++)
		{
			int current = it->second.front();
			if (current < start)
			{
				startString = it->first;
				start = current;
			}
			if (current > end)
			{
				endString = it->first;
				end = current;
			}
		}

		if (end - start < interval)
		{
			interval = end - start;
			candidateStart = start;
			candidateEnd = end;
		}

		if (m[startString].size() > 1)
		{
			m[startString].pop_front();
			while (m[startString].size() > 1)
			{
				int current = m[startString][0];
				int next = m[startString][1];

				if (current + 1 == next)
					m[startString].pop_front();
				else
					break;
			}
		}
		else
			break;
	}


	answer.push_back(candidateStart);
	answer.push_back(candidateEnd);
	return answer;
}

int main()
{
	vector<int> a;
	//a = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	//a = solution({ "AA", "AB", "AC", "AA", "AC" });
	//a = solution({ "XYZ", "XYZ", "XYZ" });
	//a = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
	a = solution({ "1","1","1","1","2","3","4","5","5","5"});
	cout << a[0] << a[1];
}