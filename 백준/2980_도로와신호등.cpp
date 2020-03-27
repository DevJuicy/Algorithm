#include <iostream>
#include <queue>

using namespace std;

int N, L;
int map[1001];
queue <pair<int, int>> RG;

void Input()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int pos, start, end;
		cin >> pos >> start >> end;
		RG.push({ start,end });
		map[pos] = 1;
	}
}

bool Light(pair<int,int> rg, int time)
{
	int size = rg.first + rg.second;

	if (time % size < rg.first % size)
		return false;
	else
	{
		RG.pop();
		return true;
	}
}

int Solution()
{
	int index = 0;
	int time = 0;
	while (index != L)
	{
		time++;
		if (map[index + 1] == 0)
			index++;
		else
		{
			if (Light(RG.front(), time))
				index++;
		}
	}
	return time;
}

int main()
{
	Input();
	cout << Solution();
}