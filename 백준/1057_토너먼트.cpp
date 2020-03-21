#include <iostream>
#include <vector>

using namespace std;

int N;
int first, second;
int answer;

void Input()
{
	cin >> N >> first >> second;
}

void Solution()
{
	while (true)
	{
		answer++;
		first = (first + 1) / 2;
		second = (second + 1) / 2;
		if (first == second)
			break;
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}