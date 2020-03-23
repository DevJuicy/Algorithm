#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> number;
int answer;

int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
}

void Solution()
{
	answer = number[0];
	int current = number[0];
	for (int i = 1; i < N; i++)
	{
		current = Max(current + number[i], number[i]);
		answer = Max(current, answer);
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}