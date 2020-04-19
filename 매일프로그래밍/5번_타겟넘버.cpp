#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> numbers;
int target;
void Input(vector<int> input, int N)
{
	numbers = input;
	target = N;
}

pair<int, int> Solution()
{
	map<int, int> m;

	for (int i = 0; i < numbers.size(); i++)
	{
		int current = target - numbers[i];
		if (m.find(current) != m.end())
		{
			return { m[current],i };
		}
		m[numbers[i]] = i;
	}
}

int main()
{
	pair<int, int> answer;
	Input({ 2,5,6,1,10 }, 8);
	answer = Solution();
	cout << answer.first << answer.second;
}