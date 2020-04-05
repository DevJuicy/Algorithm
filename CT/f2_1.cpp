#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, C;
queue<int> messages;
vector<int> consumer;
int answer;

void Input()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		messages.push(temp);
	}
}

int FindMinNumber(vector<int> &consumer)
{
	int min = 100;
	for (int i = 0; i < consumer.size(); i++)
	{
		if (min > consumer[i])
			min = consumer[i];
	}
	answer += min;
	return min;
}

int Solution()
{
	while (!messages.empty() || !consumer.empty())
	{
		int currentConsumerSize = consumer.size();
		for (int i = 0; i < C- currentConsumerSize; i++)
		{
			if (!messages.empty())
			{
				consumer.push_back(messages.front());
				messages.pop();
			}
		}

		int minNumber = FindMinNumber(consumer);
		for (int i = 0; i < consumer.size(); i++)
		{
			consumer[i] -= minNumber;
			if (consumer[i] == 0)
			{
				consumer.erase(consumer.begin() + i);
				i--;
			}
		}
	}
	return answer;
}

int main()
{
	Input();
	cout << Solution();
}