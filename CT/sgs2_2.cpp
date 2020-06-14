#include <iostream>
#include <vector>
#include <map>
using namespace std;

int day, hospitalCount, loseCount;
vector<bool> days;
map<int,bool> hospitalDay;

void Input()
{

	cin >> day >> hospitalCount >> loseCount;

	days.resize(day);
	days[0] = true;
	for (int i = 0; i < hospitalCount; i++)
	{
		int temp;
		cin >> temp;
		hospitalDay[temp] = true;
	}
}

bool Search(int startIndex)
{
	bool change = false;
	for (int i = startIndex; i < loseCount + startIndex; i++)
	{
		if (days[i])
			return true;
	}

	// ��� xxx�ΰ���ݾ�

	for (int i = startIndex; i < loseCount + startIndex; i++)
	{
		if (!hospitalDay[i])
		{
			days[i] = true;
			return true;
		}
	}

	// ��� X�ΰ�� -1
	return false;
}

int Solution()
{
	int answer = 0;
	for (int i = 1; i <= day - loseCount; i++)
	{
		if (!Search(i))
			return -1;
	}

	for (int i = 0; i < days.size(); i++)
	{
		if (days[i])
			answer++;
	}
	cout << endl;
	return answer;
}

int main()
{
	Input();
	cout << Solution();
}