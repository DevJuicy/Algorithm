#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> estimates, int k)
{
	int max = 0;
	int sum = 0;

	for (int i = 0; i < k; i++)
	{
		sum += estimates[i];
	}
	max = sum;

	for (int i = k; i < estimates.size(); i++)
	{
		sum -= estimates[i - k];
		sum += estimates[i];

		if (max < sum)
			max = sum;
	}
	return max;
}

int main()
{
	cout << solution({ 1,1,5,1,1}, 1);
}