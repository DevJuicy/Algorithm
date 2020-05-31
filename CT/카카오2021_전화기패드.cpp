#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int GetDistance(int handY, int handX, int targetY, int targetX)
{
	return abs(handY - targetY) + abs(handX - targetX);
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	int leftY, leftX, rightY, rightX;
	leftY = 3;
	leftX = 0;
	rightY = 3;
	rightX = 2;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer.push_back('L');
			leftX = 0;
			leftY = numbers[i] / 3;
			continue;
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer.push_back('R');
			rightX = 2;
			rightY = numbers[i] / 3 - 1;
			continue;
		}
		else if (numbers[i] == 0)
			numbers[i] = 10;

		int targetY = numbers[i] / 3;
		int targetX = 1;
		int leftDistance = GetDistance(leftY, leftX, targetY, targetX);
		int rightDistance = GetDistance(rightY, rightX, targetY, targetX);

		if (leftDistance < rightDistance)
		{
			leftY = targetY;
			leftX = targetX;
			answer.push_back('L');
		}
		else if (leftDistance > rightDistance)
		{
			rightY = targetY;
			rightX = targetX;
			answer.push_back('R');
		}
		else if (leftDistance == rightDistance)
		{
			if (hand == "left")
			{
				leftY = targetY;
				leftX = targetX;
				answer.push_back('L');
			}
			else
			{
				rightY = targetY;
				rightX = targetX;
				answer.push_back('R');
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 1,3,4,5,8,2,1,4,5,9,5 }, "right") << endl;
	cout << solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left") << endl;
	cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right") << endl;
}