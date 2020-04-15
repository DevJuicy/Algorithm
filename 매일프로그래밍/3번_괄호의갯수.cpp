#include <iostream>
#include <vector>

using namespace std;

vector<string> answer;

void Recursive(string current, int openCount, int closeCount,int N)
{
	if (current.size() == N * 2)
	{
		answer.push_back(current);
		return;
	}

	if (openCount < N)
	{
		Recursive(current + "(", openCount + 1, closeCount,N);
	}
	if (openCount > closeCount)
	{
		Recursive(current + ")", openCount, closeCount + 1, N);
	}
}

void Solution(int N)
{
	Recursive("", 0, 0, N);
}

int main()
{
	Solution(2);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
}