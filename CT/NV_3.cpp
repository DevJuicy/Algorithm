#include <string>
#include <vector>
#include <iostream>
using namespace std;

int frontArray[201];
int backArray[201];

void SearchBack(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		backArray[i] = -1;

		// 대문자일시
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[i] + 32 == str[j])
				{
					backArray[i] = j;
					break;
				}
			}
		}
		// 소문자일시
		else
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[i] - 32 == str[j])
				{
					backArray[i] = j;
					break;
				}
			}
		}
	}
}

void SearchFront(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		frontArray[i] = -1;

		// 대문자일시
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			for (int j = i + 1; j < str.size(); j++)
			{
				if (str[i] + 32 == str[j])
				{
					frontArray[i] = j;
					break;
				}
			}
		}
		// 소문자일시
		else
		{
			for (int j = i + 1; j < str.size(); j++)
			{
				if (str[i] - 32 == str[j])
				{
					frontArray[i] = j;
					break;
				}
			}
		}
	}
}

int solution(string str)
{
	SearchFront(str);
	SearchBack(str);

	int shortest = INT_MAX;
	int start, end;

	for (int i = 0; i < str.size(); i++)
	{
		if (frontArray[i] == -1)
			continue;

		start = i;
		end = frontArray[i];

		for (int j = start + 1; j < end; j++)
		{
			if (frontArray[j] == -1 && backArray[j] == -1)
			{
				start = -1;
				end = -1;
				break;
			}

			if (frontArray[j] > end)
				end = frontArray[j];
			else
			{
				if (backArray[j] != -1 && backArray[j] < start)
				{
					start = -1;
					end = -1;
					break;
				}
			}
		}


		if (start == end)
			continue;


		if (shortest > end - start + 1)
			shortest = end - start + 1;
	}

	if (shortest == INT_MAX)
		shortest = -1;

	return shortest;
}

int main()
{
	solution("TacoCat");
}