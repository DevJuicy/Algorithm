#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int ParseToMin(string time)
{
	string h;
	h += time[0];
	h += time[1];
	int hour = stoi(h);

	string m;
	m += time[3];
	m += time[4];
	int min = stoi(m);

	return hour * 60 + min;
}

string ParseToString(int time)
{
	string ret;
	if (time / 60 < 10)
		ret = "0";
	ret += to_string(time/60);
	ret += ":";

	if (time % 60 < 10)
		ret += "0";
	ret += to_string(time % 60);
	return ret;
}

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";
	vector<int> min;
	vector<pair<int, int>> busTime;

	min.resize(timetable.size());

	for (int i = 0; i < timetable.size(); i++)
	{
		min[i] = ParseToMin(timetable[i]);
	}
	sort(min.begin(), min.end());

	// 2, 10 ,2

	int timeWeight = 540;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			busTime.push_back({ timeWeight,0 });
		timeWeight += t;
	}

	int busIndex = 0;

	for (int i = 0; i < min.size(); i++)
	{
		for (; busIndex < busTime.size(); busIndex++)
		{
			if (busTime[busIndex].second != 0)
				continue;

			if (min[i] <= busTime[busIndex].first)
			{
				busTime[busIndex].second = min[i];
				busIndex++;
				break;
			}
		}
	}

	int answerMin;
	if (busTime[busTime.size() - 1].second == 0)
	{
		answerMin = busTime[busTime.size() - 1].first;
	}
	else
	{
		answerMin = busTime[busTime.size() - 1].second - 1;
	}
	answer = ParseToString(answerMin);
	return answer;
}

int main()
{
	//solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
	cout << solution(2, 10, 2, { "09:10", "09:09", "08:00" });

}