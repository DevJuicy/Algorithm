#include <iostream>
#include <vector>

using namespace std;

int A, B, C;
int park[101];
int minNum = 101;
int maxNum;
int answer;

void Input()
{
	cin >> A >> B >> C;
	B *= 2;
	C *= 3;

	for (int i = 0; i < 3; i++)
	{
		int start, end;
		cin >> start >> end;
		for (int i = start; i < end; i++)
			park[i]++;
		
		if (start < minNum)
			minNum = start;
		if (end > maxNum)
			maxNum = end;
	}
}

void Solution()
{
	for (int i = minNum; i < maxNum; i++)
	{
		if (park[i] == 1)
			answer += A;
		else if (park[i] == 2)
			answer += B;
		else if (park[i] == 3)
			answer += C;
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}