#include <iostream>
#include <vector>

using namespace std;

int Find(string s1, string s2)
{
	for (int i = 0; i < s1.size(); i++)
	{
		bool find = true;
		for (int j = 0; i + j < s1.size(); j++)
		{
			if (s1[i + j] != s2[j])
			{
				find = false;
				break;
			}
		}
		if (find)
			return s1.size()-i;
	}
	return s1.size();
}

int Solution(string s1, string s2)
{
	int answer = 0;

	int first = s1.size() + s2.size() - Find(s1, s2);
	int second = s1.size() + s2.size() - Find(s2, s1);

	if (first > second)
		answer = second;
	else
		answer = first;

	return answer;
}