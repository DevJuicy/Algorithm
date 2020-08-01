#include <iostream>
#include <vector>
using namespace std;


vector<int> solution(vector<int> arr1, vector<int> arr2)
{
	vector<int> answer;
	int priceBuffer = 0;

	for (int i = 0; i < arr1.size(); i++)
	{
		answer.push_back(arr1[i] - arr2[i]);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] < 0)
		{
			priceBuffer += answer[i];
			answer[i] = 0;
			continue;
		}

		if (priceBuffer * -1 < answer[i])
		{
			answer[i] += priceBuffer;
			priceBuffer = 0;
		}
		else
		{
			priceBuffer += answer[i];
			answer[i] = 0;
		}
	}
	return answer;
}

int main()
{
	vector<int> ans = 
	solution({ 100,300,10,0,40,0,0,70,65 }
	, { 40,300,20,10,10,20,100,10,0 });

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}