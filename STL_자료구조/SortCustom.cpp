#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> b, pair<int, int> a) // sort는 거꾸로 들어옴
{
	// 만약 오름차순으로 정렬한다고하면
	if (a.first == b.first)
	{
		//if (a.second >= b.second)
		//	return true;
		//return false;
		return a.second > b.second;
	}

	//if (a.first > b.first)
		//	return true;
		//return false;
	return a.first > b.first;
}

int main()
{
	vector<pair<int, int>> vec;
	vec.push_back({ 3,2 });
	vec.push_back({ 4,1 });
	vec.push_back({ 4,3 });
	vec.push_back({ 3,1 });
	vec.push_back({ 1,6 });
	vec.push_back({ 2,3 });

	sort(vec.begin(), vec.end(), Compare);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << " / " << vec[i].second << endl;
	}
}