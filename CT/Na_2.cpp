#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> Solution(vector<string> words)
{
	vector<int> answer;
	map<string, int> m;
	
	for (int i = 0; i < words.size(); i++)
	{
		if (m.find(words[i]) == m.end())
		{
			m[words[i]] = i + 1;
		}
		answer.push_back(m[words[i]]);
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return answer;
}