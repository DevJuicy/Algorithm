#include <iostream>
#include <vector>

using namespace std;
int N1, N2;
string str1, str2;
int time;
vector<char> road;
vector<bool> bRoad;

void Swap(int j)
{
	char temp = road[j];
	road[j] = road[j + 1];
	road[j + 1] = temp;

	bRoad[j] = false;
	bRoad[j + 1] = true;
}

void Input()
{
	cin >> N1 >> N2;
	cin >> str1 >> str2;
	for (int i = 0; i < N1; i++)
	{
		road.push_back(str1[N1 - 1 - i]);
		bRoad.push_back(true);
	}
	for (int i = 0; i < N2; i++)
	{
		road.push_back(str2[i]);
		bRoad.push_back(false);
	}
	cin >> time;
}

void Solution()
{
	for (int i = 0; i < time; i++)
	{
		for (int j = 0; j < road.size()-1; j++)
		{
			if (bRoad[j] && !bRoad[j+1])
			{
				Swap(j);
				j++;
			}
		}
	}
}

int main()
{
	Input();
	Solution();
	for (int j = 0; j < road.size(); j++)
	{
		cout << road[j];
	}
}