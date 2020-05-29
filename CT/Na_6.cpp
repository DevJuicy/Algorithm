#include <iostream>
#include <vector>

using namespace std;

vector<int> xDragons;
vector<int> oDragons;
vector<int> eggs;

void DoOdragons()
{
	for (int i = 0; i < oDragons.size(); i++)
	{
		oDragons[i]++;
		if (oDragons[i] <= 4)
		{
			eggs.push_back(0);
		}

		if (oDragons.size() > 4)
		{
			xDragons.push_back(0);
			oDragons.erase(oDragons.begin() + i);
			i--;
		}
	}
}

void DoEgg()
{
	for (int i = 0; i < eggs.size(); i++)
	{
		eggs[i]++;
		if (eggs[i] == 2)
		{
			oDragons.push_back(0);
			eggs.erase(eggs.begin() + i);
			i--;
		}
	}
}

int Solution(int day)
{
	eggs.push_back(0);

	for (int i = 1; i <= day; i++)
	{
		DoEgg();
		DoOdragons();
	}
	return eggs.size()+oDragons.size()+xDragons.size();
}