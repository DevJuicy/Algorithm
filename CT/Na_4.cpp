#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int Solution(vector<int> estimates, int k)
{
	int answer;
	int sum = 0;

	for (int i = 0; i < k; i++)
		sum += estimates[i];
	answer = sum;

	for (int i = 1; i < estimates.size() - k + 1; i++)
	{
		sum = sum - estimates[i - 1] + estimates[i + k - 1];
		answer = Max(answer, sum);
	}
	return answer;
}