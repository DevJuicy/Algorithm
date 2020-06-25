#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<priority_queue<int>> teams;

int solution(vector<int> stats)
{
	priority_queue<int> init;
	init.push(stats[0]);
	teams.push_back(init);

	for (int i = 1; i < stats.size(); i++)
	{
		for (int j = 0; j < teams.size(); j++)
		{
			if (teams[j].top() < stats[i])
			{
				teams[j].push(stats[i]);
				break;
			}

			if (j == teams.size() - 1)
			{
				priority_queue<int> temp;
				temp.push(stats[i]);
				teams.push_back(temp);
				break;
			}
		}
	}

	for (int i = 0; i < teams.size(); i++)
	{
		while (!teams[i].empty())
		{
			cout << teams[i].top() << " ";
			teams[i].pop();
		}
		cout << endl;
	}

	return teams.size();
}

int main()
{
	solution({ 5,3,4,6,2,1 });
}