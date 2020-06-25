#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Concat(string s1, string s2)
{
	int ret = 0;
	int size = s1.size();
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (s1[size - i + j] != s2[j])
				break;

			if (j == i - 1)
				ret = i;
		}
	}
	return ret;
}

int  solution(string s1, string s2)
{
	int total = s1.size() + s2.size();
	int min = total - max(Concat(s1, s2), Concat(s2, s1));

	return min;
}

int main()
{
	cout << solution("ababc", "abcdab");
}