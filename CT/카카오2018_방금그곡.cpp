// 27테스트케이스 통과못함 ㅠ

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> Tokenize(string ids)
{
	vector<string> tokenizeList;
	string token;
	stringstream ss(ids);
	while (getline(ss, token, ','))
	{
		tokenizeList.push_back(token);
	}
	return tokenizeList;
}

int PareseToTime(string a, string b)
{
	string firstHour, firstMin, secondHour, secondMin;
	firstHour += a[0];
	firstHour += a[1];
	secondHour += b[0];
	secondHour += b[1];
	firstMin += a[3];
	firstMin += a[4];
	secondMin += b[3];
	secondMin += b[4];

	int min = (stoi(secondHour) * 60 + stoi(secondMin)) - (stoi(firstHour) * 60 + stoi(firstMin));
	return min;
}
string ParseToCode(string a)
{
	string ret;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '#')
		{
			ret[ret.size() - 1] += 13;
		}
		else
		{
			ret += a[i];
		}
	}
	return ret;
}

bool CompareCode(string origin, string target, int time)
{
	int multipleValue = time / target.size();
	string targetSequnce;
	for (int i = 0; i < multipleValue; i++)
		targetSequnce += target;

	if (time % target.size() != 0)
		for (int i = 0; i < time % target.size(); i++)
			targetSequnce += target[i];

	int find = targetSequnce.find(origin);

	if (find == -1)
		return false;
	else
		return true;
}

string solution(string m, vector<string> musicinfos)
{
	string answer = "";

	vector<vector<string>> info;
	vector<int> time;
	vector<bool> isRight;
	vector<pair<int, string>> candidate;

	m = ParseToCode(m);

	for (int i = 0; i < musicinfos.size(); i++)
	{
		info.push_back(Tokenize(musicinfos[i]));
		info[i][3] = ParseToCode(info[i][3]);
		time.push_back(PareseToTime(info[i][0], info[i][1]));
	}

	for (int i = 0; i < info.size(); i++)
	{
		isRight.push_back(CompareCode(m, info[i][3], time[i]));
	}

	for (int i = 0; i < isRight.size(); i++)
	{
		if (isRight[i])
		{
			candidate.push_back({ time[i],info[i][2] });
		}
	}
	if (candidate.size() > 0)
	{
		sort(candidate.begin(), candidate.end());
		answer = candidate[candidate.size() - 1].second;
	}
	else
	{
		answer = "(None)";
	}
	return answer;
}

int main()
{
	cout << solution(
		{ "CC" }, {
		"04:00,04:02,ZERO,B#CC",
		"15:00,15:02,FIRST,B#CC",
		"04:04,04:06,SECOND,B#CC",
		"04:08,04:10,THIRD,B#CC"
		});

}