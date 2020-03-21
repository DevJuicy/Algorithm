#include <iostream>
#include <vector>
using namespace std;

int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int solution(vector<int> input)
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
	cout << solution({ -1,-3,-1,5 }) << endl;
	cout << solution({ -5,-3,-1 }) << endl;
	cout << solution({ 2,4,-2,-3,8 }) << endl;
}