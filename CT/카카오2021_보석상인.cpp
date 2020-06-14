#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> gemMap;
int gemKinds;

pair<int, int> SearchGems(vector<string>& gems, int length)
{
	for (int i = 0; i <= gems.size() - length; i++)
	{
		map<string, bool> hasGem;
		for (int j = 0; j < length; j++)
			hasGem[gems[i + j]] = true;

		if (hasGem.size() == gemKinds)
		{
			return { i+1,i + length };
		}
	}

	return { -1,-1 };
}

vector<int> solution(vector<string> gems)
{
	vector<int> answer;
	for (int i = 0; i < gems.size(); i++)
	{
		gemMap[gems[i]]++;
	}

	int min = gemMap.size();
	gemKinds = gemMap.size();
	int max = gems.size();

	pair<int, int> range;
	while (min <= max)
	{
		int mid = (min + max) / 2;
		range = SearchGems(gems, mid);
		if (range == make_pair(-1, -1)) // 길이늘려
		{
			min = mid + 1;
		}
		else // 길이줄여
		{
			max = mid - 1;
		}
	}

	answer.push_back(range.first);
	answer.push_back(range.second);
	return answer;
}

int main()
{
	vector<int> answer =

		//solution({
		//	"DIA", "RUBY", "RUBY",
		//	"DIA", "DIA", "EMERALD",
		//	"SAPPHIRE", "DIA" });

		//solution({ "AA","AB","AC","AA","AC" });

		//solution({ "XYZ","XYZ","XYZ" });

		solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });

	cout << answer[0] << " " <<answer[1];
}