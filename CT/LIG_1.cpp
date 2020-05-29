#include <iostream>
#include <vector>

using namespace std;

int open[4];
int close[4];

bool FindCase(char c)
{
	if (c == '(')
	{
		open[0]++;
	}
	else if (c == '{')
	{
		open[1]++;
	}
	else if (c == '[')
	{
		open[2]++;
	}
	else if (c == '<')
	{
		open[3]++;
	}
	else if (c == ')')
	{
		close[0]++;
		if (open[0] < close[0])
			return false;
	}
	else if (c == '}')
	{
		close[1]++;
		if (open[1] < close[1])
			return false;
	}
	else if (c == ']')
	{
		close[2]++;
		if (open[2] < close[2])
			return false;
	}
	else if (c == '>')
	{
		close[3]++;
		if (open[3] < close[3])
			return false;
	}
	return true;
}

int Solution(string input)
{
	int answer = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (!FindCase(input[i]))
			return -1;
	}
	for (int i = 0; i < 4; i++)
	{
		answer += open[i];
	}
	return answer;
}