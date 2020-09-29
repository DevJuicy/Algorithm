#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> S)
{
	int N = S.size();
	int M = S[0].size();
	map<char, int> m;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char current = S[j][i];

			if (m.find(current) == m.end())
			{
				m[current] = j;
			}
			else
			{
				return { m[current],j,i };
			}
		}
		m.clear();
	}
}

int main()
{
	vector<int> ret = solution({ "bdafg","ceagi"});

	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
}