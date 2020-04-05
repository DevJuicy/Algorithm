#include <iostream>
#include <vector>

using namespace std;

int map[25][25];
int mapY, mapX, conyY, conyX;

void Input()
{
	cin >> mapY >> mapX >> conyY >> conyX;
}

void Solution()
{
	if (conyY > mapY || conyX > mapX)
	{
		cout << "fail";
		return;
	}

	for (int i = 0; i <= conyY; i++)
		map[i][0] = 1;
	for (int i = 0; i <= conyX; i++)
		map[0][i] = 1;

	for (int i = 1; i <= conyY; i++)
	{
		for (int j = 1; j <= conyX; j++)
		{
			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}

	cout << conyY + conyX << endl;
	cout << map[conyY][conyX];
}

int main()
{
	Input();
	Solution();
}