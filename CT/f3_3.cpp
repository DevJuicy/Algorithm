#include <iostream>
#include <vector>

using namespace std;

vector<int> one;
vector<int> zero;
vector<int> answers;

void ConnectRoad(int roadCount, bool isOne)
{
	if (isOne)
	{
		zero.push_back(0);
		for (int j = 0; j < one.size(); j++)
		{
			int sum = 0;
			int currentZero = 0;
			for (int i = j; i < one.size(); i++)
			{
				sum += one[i];
				currentZero += zero[i];
				if (roadCount < currentZero)
					break;

				sum += zero[i];
			}
			answers.push_back(sum);
		}
	}
	else
	{
		one.push_back(0);
		for (int j = 0; j < zero.size(); j++)
		{
			int sum = 0;
			int currentZero = 0;
			for (int i = j; i < zero.size(); i++)
			{
				sum += one[i];
				currentZero += zero[i];
				if (roadCount < currentZero)
					break;

				sum += zero[i];
			}
			answers.push_back(sum);
		}
	}
}

int Solution(string road, int n)
{
	int answer = 0;
	int currentNum = road[0];
	int seq = 1;
	for (int i = 1; i < road.size(); i++)
	{
		if (road[i] == currentNum)
			seq++;
		else
		{
			if (currentNum == '0')
				zero.push_back(seq);
			else
				one.push_back(seq);
			currentNum = road[i];
			seq = 1;
		}

		if (i == road.size() - 1)
		{
			if (currentNum == '0')
				zero.push_back(seq);
			else
				one.push_back(seq);
		}
	}

	bool isOne;
	if (road[0] == '0')
		isOne = false;
	else
		isOne = true;
	ConnectRoad(n,isOne);

	int maxValue = 0;
	for (int i = 0; i< answers.size(); i++)
	{
		if (maxValue < answers[i])
			maxValue = answers[i];
	}
	return maxValue;
}

int main()
{
	cout << Solution({ "001100" }, 5);
}