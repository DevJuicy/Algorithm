#include <iostream>
#include <vector>

using namespace std;

enum Health
{
	DONT_KNOW, GO, NOT_GO
};

int solution(int day, int lose, vector<int> hospital)
{
	int answer = 0;
	vector<int> days;
	days.resize(day);
	days[0] = GO;
	
	for (int i = 0; i < hospital.size(); i++)
		days[hospital[i]] = NOT_GO;

	int currentIndex = 0;
	while (currentIndex + lose < day)
	{
		currentIndex += lose;

		if (days[currentIndex] != NOT_GO)
		{
			days[currentIndex] = GO;
			continue;
		}


		for (int i = 0; i < lose - 1; i++)
		{
			currentIndex--;
			if (days[currentIndex] != NOT_GO)
			{
				days[currentIndex] = GO;
				break;
			}

			if (i == lose - 1)
			{
				return -1;
			}
		}
	}

	for (int i = 0; i < days.size(); i++)
	{
		if (days[i] == GO)
			answer++;
	}
	return answer;
}

int main()
{
	cout << solution(7, 3, { 1,2,6 });
}