#include <iostream>
#include <vector>

using namespace std;

string solution(string phrases, int second)
{
	string answer = "";
	second %= 28;

	if (second <= 14)
	{
		for (int i = 0; i < 14 - second; i++)
		{
			answer += '_';
		}

		for (int i = 0; i < second; i++)
		{
			answer += phrases[i];
		}
	}
	else
	{
		second %= 14;

		for (int i = second; i < 14; i++)
		{
			answer += phrases[i];
		}

		for (int i = 0; i < 14 - second; i++)
		{
			answer += '_';
		}
	}
	return answer;
}

int main()
{
	cout << solution("happy-birthday", 29);
}