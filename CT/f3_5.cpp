#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, string>> dataPairs;
map<string, bool> tagMap;

bool Compare(pair<int, string> a, pair<int, string> b)
{
	if (a.first == b.first)
	{
		if (b.second.compare(a.second) == 1)
			return true;
		return false;
	}
	return a.first > b.first;
}

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags)
{
	vector<string> answer;

	for (int i = 0; i < tags.size(); i++)
		tagMap[tags[i]] = true;


	for (int i = 0; i < dataSource.size(); i++) // 10만 스퀘어라 시간초과날꺼같은데 확인할 수가 없음
	{
		int cnt = 0;
		for (int j = 1; j < dataSource[i].size(); j++)
		{
			if (tagMap[dataSource[i][j]])
				cnt++;
		}
		if (cnt > 0)
			dataPairs.push_back({ cnt,dataSource[i][0] });
	}

	sort(dataPairs.begin(), dataPairs.end(), Compare);

	for (int i = 0; i < dataPairs.size(); i++)
	{
		if (answer.size() == 10)
			break;

		answer.push_back(dataPairs[i].second);
	}

	return answer;
}

int main()
{
	solution({ {"doc1", "t1", "t2", "t3"}
					,{"doc2", "t0", "t2", "t3"}
					,{"doc3", "t1", "t6", "t7"}
					,{"doc4", "t1", "t2", "t4"}
					,{"doc5", "t6", "t100", "t8"} }
	, { "t1", "t2", "t3" });
}