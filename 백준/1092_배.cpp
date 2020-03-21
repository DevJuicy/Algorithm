#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> cranes;
vector<int> boxes;
int answer;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cranes.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		boxes.push_back(temp);
	}
}

void Sort()
{
	sort(cranes.begin(), cranes.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());
}

void Solution()
{
	while (!boxes.empty())
	{
		for (int i = 0; i < cranes.size(); i++)
		{
			for (int j = 0; j < boxes.size(); j++)
			{
				if (boxes[j] <= cranes[i])
				{
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
		answer++;
	}
}

int main()
{
	Input();
	Sort();
	if (boxes[0] > cranes[0])
		answer = -1;
	else
		Solution();
	cout << answer;
}