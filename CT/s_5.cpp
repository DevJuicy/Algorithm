#include <iostream>
#include <vector>

using namespace std;

int Solution(vector<int> stats)
{
	vector<int> ans;
	ans.push_back(stats[0]);

	for (int i = 1; i < stats.size(); i++)
	{
		for (int j = 0; j < ans.size(); j++)
		{
			if (ans[j] < stats[i])
			{
				ans[j] = stats[i];
				break;
			}
			else
			{
				if (j == ans.size() - 1)
				{
					ans.push_back(stats[i]);
					break;
				}
			}
		}
	}
	return ans.size();
}
