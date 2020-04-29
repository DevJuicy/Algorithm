#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> banIndex;
vector<vector<int>> candidates;

bool HasElement(vector<int>& vec, int element)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == element)
			return true;
	}
	return false;
}

void Recursive(vector<int> buffer, int size)
{

	if (size == banIndex.size())
	{
		candidates.push_back(buffer);
		return;
	}

	for (int i = 0; i < banIndex[size].size(); i++)
	{

		int currentElement = banIndex[size][i];
		if (HasElement(buffer, currentElement))
			continue;
		vector<int> temp = buffer;
		temp.push_back(banIndex[size][i]);
		Recursive(temp, size + 1);
	}
}

bool CompareID(string user, string ban)
{
	if (user.size() != ban.size())
		return false;

	for (int i = 0; i < user.size(); i++)
	{

		if (ban[i] == '*')
			continue;

		if (user[i] != ban[i])
			return false;
	}
	return true;
}


int solution(vector<string> user_id, vector<string> banned_id)
{
	int answer = 0;
	banIndex.resize(banned_id.size());

	for (int i = 0; i < banned_id.size(); i++)
	{
		for (int j = 0; j < user_id.size(); j++)
		{
			if (CompareID(user_id[j], banned_id[i]))
			{
				banIndex[i].push_back(j);
			}
		}
	}

	vector<int> buffer;
	Recursive(buffer, 0);

	for (int i = 0; i < candidates.size(); i++)
	{
		sort(candidates[i].begin(), candidates[i].end());
	}
	sort(candidates.begin(), candidates.end());

	candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

	return candidates.size();
}

int main()
{
	//solution
	//(
	//	{ "frodo", "fradi", "crodo", "abc123", "frodoc" },
	//	{ "fr*d*", "abc1**" }
	//);

	cout << solution
	(
		{ "frodo", "fradi", "crodo", "abc123", "frodoc" },
		{ "*rodo", "*rodo", "******" }
	);

	/*cout << solution
	(
		{ "frodo", "fradi", "crodo", "abc123", "frodoc" },
		{ "fr*d*", "*rodo", "******", "******" }
	);*/
}