#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<int> visitedIndex;

int voteSize;
int currentCount;
int startIndex;
int answer;

void FindThreeCircle(int index, vector<int>& vote)
{
	currentCount++;
	int childIndex = vote[index];

	if (currentCount == 3)
	{
		if (childIndex == startIndex)
		{
			answer++;
			for (int i = 0; i<visitedIndex.size(); i++)
				visited[visitedIndex[i]] = true;
			return;
		}
		else
		{
			return;
		}
	}

	if (visited[childIndex])
		return;

	visitedIndex.push_back(childIndex);
	FindThreeCircle(childIndex, vote);
}

int Solution(vector<int> vote)
{
	for (int i = 0; i < vote.size(); i++)
		vote[i]--;

	visited.resize(vote.size());
	for (int i = 0; i < vote.size(); i++)
	{
		if (visited[i])
			continue;

		visitedIndex.clear();
		visitedIndex.push_back(i);
		currentCount = 0;
		startIndex = i;
		FindThreeCircle(i, vote);
	}
	return answer;
}

int main()
{
	cout << Solution({ 2,3,4,1,6,7,5 });
}