#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int N;
int maxNum;
vector<int> weight;
vector<int> answer;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		weight.push_back(temp);
	}
	sort(weight.begin(), weight.end());
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		// NÀº i+1
		int min = 10000;
		for (int j = 0; j <= i; j++)
		{
			if (min > weight[j])
				min = weight[j];
		}

		if (maxNum > min* (i + 1))
		{
			maxNum = min * (i + 1);
			break;
		}
		maxNum = min * (i + 1);
	}
	cout << maxNum;
}

int main()
{
	Input();
	Solution();
}