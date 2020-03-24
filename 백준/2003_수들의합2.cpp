#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
int answer;

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		int sum = arr[i];
		if (sum == M)
		{
			answer++;
			continue;
		}
		for (int j = i+1; j < N; j++)
		{
			sum += arr[j];
			if (sum > M)
				break;
			else if (sum == M)
			{
				answer++;
				break;
			}
		}
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}