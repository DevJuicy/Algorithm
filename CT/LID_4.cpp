#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> position;
vector<int> leftLength;
vector<int> rightLength;

int Min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void Input()
{
	cin >> N;
	leftLength.resize(N);
	rightLength.resize(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		position.push_back(temp);
	}
}

int Solution()
{
	int answer = 0;
	//right find
	for (int i = 0; i < N - 1; i++)
	{
		if (position[i] == 1)
			continue;

		int cnt = 1;
		for (int j = i + 1; j < N; j++)
		{
			if (position[j] == 0)
				cnt++;
			else
				break;
		}
		rightLength[i] = cnt;
	}

	// left find
	for (int i = 1; i < N; i++)
	{
		if (position[i] == 1)
			continue;

		int cnt = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (position[j] == 0)
				cnt++;
			else
				break;
		}
		leftLength[i] = cnt;
	}

	for (int i = 0; i < position.size(); i++)
		position[i] = Min(leftLength[i], rightLength[i]);
	

	for (int i = 0; i < position.size(); i++)
	{
		if (position[i] == 0)
			continue;

		if (answer < position[i])
			answer = position[i];
	}
	return answer;
}

int main()
{
	Input();
	cout << Solution();
}