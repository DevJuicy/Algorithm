#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, L;
vector<int> position;
queue<int> qPostion;
int answer;

void Input()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		position.push_back(temp);
	}
}

void Sort()
{
	sort(position.begin(), position.end());
	for (int i = 0; i < position.size(); i++)
		qPostion.push(position[i]);
}

void Solution()
{
	while (!qPostion.empty())
	{
		int start = qPostion.front();
		qPostion.pop();
		answer++;
		while (!qPostion.empty())
		{
			if (qPostion.front() < start+L)
				qPostion.pop();
			else
				break;
		}
	}
}

int main()
{
	Input();
	Sort();
	Solution();
	cout << answer;
}