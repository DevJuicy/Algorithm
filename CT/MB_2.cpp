#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> words)
{
	vector<int> answer;
	map<string, int> m;

	for (int i = 0; i < words.size(); i++)
	{
		if (m.find(words[i]) == m.end())
		{
			m[words[i]] = i + 1;
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		answer.push_back(m[words[i]]);
	}

	return answer;
}

int main()
{
	solution({ "one","one","two","one" });
}