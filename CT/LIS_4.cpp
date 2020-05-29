#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> bufferStack;

int PlusExcept(int current)
{
	if (current == 5)
	{
		bufferStack.push(5);
		return 19;
	}
	else if (current == 10)
	{
		bufferStack.push(10);
		return 24;
	}
	else if (current == 22)
	{
		bufferStack.push(22);
		return 27;
	}
	return current;
}

int MinusExcept(int current)
{
	if (current == 19)
	{
		bufferStack.pop();
		return 5;
	}
	else if (current == 24 && bufferStack.top() == 10)
	{
		bufferStack.pop();
		return 10;
	}
	else if (current == 27 && bufferStack.top() == 22)
	{
		bufferStack.pop();
		return 22;
	}
	return current;
}

int solution(vector<int> inputList)
{
	int answer = 0;
	for (int i = 0; i < inputList.size(); i++)
	{
		if (inputList[i] > 0)
		{
			answer = PlusExcept(answer);
			answer += inputList[i];
		}
		else
		{
			answer = MinusExcept(answer);
			answer += inputList[i];
		}

		if (answer >= 25)
		{
			if (bufferStack.top() == 5)
				answer -= 10;
		}
		if (answer == 0 || answer > 29)
			return 0;
	}

	if (answer == 28 || answer == 29)
		return answer - 1;
	else if (answer == 27)
		return 22;

	return answer;
}

int main()
{
	cout << solution({ 4, 4, 2, 4, -1, -1 });
}