#include <iostream>
#include <vector>

using namespace std;

class Egg
{
public:
	int day = 0;
	Egg(int i)
	{
		day = i;
	}
};

class Dragon
{
public:
	int day = -1;
};

void ExecuteEggs(std::vector<Egg>& eggs, std::vector<Dragon>& dragons);

void ExecuteDragons(std::vector<Dragon>& dragons, std::vector<Egg>& eggs);

int solution(int n)
{
	vector<Egg> eggs;
	vector<Dragon> dragons;
	eggs.push_back(Egg(-1));

	for (int i = 0; i <= n; i++)
	{
		ExecuteEggs(eggs, dragons);
		ExecuteDragons(dragons, eggs);

		cout << "¾Ë : " << eggs.size() << " µå·¡°ï : " << dragons.size() << endl;
	}
	cout << endl;
	return eggs.size() + dragons.size();
}

void ExecuteEggs(std::vector<Egg>& eggs, std::vector<Dragon>& dragons)
{
	for (int j = 0; j < eggs.size(); j++)
	{
		if (eggs[j].day < 1)
			eggs[j].day++;
		else if (eggs[j].day == 1)
		{
			eggs.erase(eggs.begin() + j);
			dragons.push_back(Dragon());
			j--;
		}
	}
}

void ExecuteDragons(std::vector<Dragon>& dragons, std::vector<Egg>& eggs)
{
	for (int j = 0; j < dragons.size(); j++)
	{
		if (dragons[j].day < 3)
		{
			dragons[j].day++;
			eggs.push_back(Egg(0));
		}
	}
}

int main()
{
	cout << solution(6);
}