#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> input;

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
		input.push_back(temp);
	}
}

int solution()
{
	int maxValue = input[0];
	int currentValue = input[0];

	for (int i = 1; i < input.size(); i++)
	{
		currentValue = Max(currentValue + input[i], input[i]);
		maxValue = Max(currentValue, maxValue);
	}
	return maxValue;
}

int main()
{
	Input();
	cout << solution() << endl;
}