#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> gap;
vector<bool> real;
map<int, int> m;

int Solution(int k, vector<int> score)
{
	real.resize(score.size());
	// ���� ���ϱ�
	gap.push_back(-1);
	for (int i = 1; i < score.size(); i++)
	{
		gap.push_back(score[i - 1] - score[i]);
	}

	// �ߺ��� �� ã��
	for (int i = 1; i < gap.size(); i++)
	{
		if (m.find(gap[i]) == m.end())
		{
			m[gap[i]] = 1;
		}
		else
		{
			m[gap[i]]++;
		}
	}

	for (int i = 1; i < gap.size(); i++)
	{
		if (m[gap[i]] >= k)
		{
			real[i - 1] = true;
			real[i] = true;
		}
	}

	int answer = 0;
	for (int i = 0; i < real.size(); i++)
	{
		if (!real[i])
			answer++;
	}

	return answer;
}

int main()
{
	cout << Solution(2, { 1300000000,700000000,668239490,618239490,568239490,568239486,518239486,157658638,157658634,100000000,100 });
}