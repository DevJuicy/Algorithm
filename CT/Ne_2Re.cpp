#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int solution(int k, vector<int> score)
{
	int answer = 0;

	map<int, int> gapCount;
	vector<int> scoreGap;

	scoreGap.push_back(0);
	for (int i = 1; i < score.size(); i++)
	{
		int gap = score[i - 1] - score[i];
		gapCount[gap]++;
		scoreGap.push_back(gap);
	}

	for (int i = 1; i < scoreGap.size(); i++)
	{
		if (gapCount[scoreGap[i]] >= k)
		{
			scoreGap[i - 1] = -1;
			scoreGap[i] = -1;
		}
	}

	for (int i = 0; i < scoreGap.size(); i++)
	{
		if (scoreGap[i] == -1)
			continue;
		answer++;
	}

	return answer;
}

int main()
{
	//cout << solution(3, { 24,22,20,10,5,3,2,1 });
	//cout << solution(2, { 1300000000,700000000,668239490,618239490,568239490,568239486,518239486,157658638,157658634,100000000,100 });
}