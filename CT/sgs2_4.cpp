#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, remainGas, stationCount;
vector<int> stationPosition;
vector<int> stationGas;
vector<pair<int, int>> stationGasPos;

bool Compare(pair<int, int> b, pair<int, int> a)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

void Input()
{
	cin >> N >> remainGas >> stationCount;
	for (int i = 0; i < stationCount; i++)
	{
		int temp;
		cin >> temp;
		stationPosition.push_back(temp);
	}
	for (int i = 0; i < stationCount; i++)
	{
		int temp;
		cin >> temp;
		stationGas.push_back(temp);
	}
	for (int i = 0; i < stationCount; i++)
	{
		stationGasPos.push_back({ stationGas[i],stationPosition[i] });
	}
	sort(stationGasPos.begin(), stationGasPos.end(), Compare);
}

int Solution()
{
	int answer = 0;

	int currentPosition = 0;
	while (currentPosition + remainGas < N)
	{
		bool able = false;
		for (int i = 0; i < stationGasPos.size(); i++)
		{
			int maxGas = stationGasPos[i].first;
			int maxPos = stationGasPos[i].second;

			if (remainGas < maxPos)
				continue;

			able = true;
			answer++;
			currentPosition += maxPos;
			remainGas -= maxPos;
			remainGas += maxGas;
			stationGasPos.erase(stationGasPos.begin() + i);
			break;
		}

		if (!able)
			return -1;
	}
	return answer;
}

int main()
{
	Input();
	cout << Solution();
}