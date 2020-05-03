#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> map1;
map<string, int> map2;

bool IsAlphabet(char c)
{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		return true;
	return false;
}

vector<string> ExtractElements(string str)
{
	vector<string> vec;
	for (int i = 0; i < str.size() - 1; i++)
	{
		string temp = "";
		if (IsAlphabet(str[i]) && IsAlphabet(str[i + 1]))
		{
			temp += toupper(str[i]);
			temp += toupper(str[i + 1]);
			vec.push_back(temp);
		}
	}
	return vec;
}

void MappingWordCounts(vector<string>& vecStr, map<string, int>& m)
{
	for (int i = 0; i < vecStr.size(); i++)
		m[vecStr[i]]++;
}

void EraseOverlap(vector<string>& str)
{
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
}

void MergeVector(vector<string>& str1, vector<string>& str2)
{
	for (int i = 0; i < str2.size(); i++)
		str1.push_back(str2[i]);
}

int CompareIntersection(vector<string>& str)
{
	int intersectionCount = 0;
	for (int i = 0; i < str.size(); i++)
		intersectionCount += min(map1[str[i]], map2[str[i]]);
	return intersectionCount;
}

int CompareUnion(vector<string>& str)
{
	int unionCount = 0;
	for (int i = 0; i < str.size(); i++)
		unionCount += max(map1[str[i]], map2[str[i]]);
	return unionCount;
}

int solution(string str1, string str2)
{
	int answer = 0;
	int intersectionCount = 0;
	int unionCount = 0;

	vector<string>vec1;
	vector<string>vec2;

	vec1 = ExtractElements(str1);
	vec2 = ExtractElements(str2);

	MappingWordCounts(vec1, map1);
	MappingWordCounts(vec2, map2);

	MergeVector(vec1, vec2);
	EraseOverlap(vec1);

	intersectionCount = CompareIntersection(vec1);
	unionCount = CompareUnion(vec1);

	if (unionCount == 0)
		return 65536;

	answer = (float)intersectionCount / unionCount * 65536;

	return answer;
}
