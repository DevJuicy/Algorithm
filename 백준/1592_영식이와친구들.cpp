#include <iostream>
#include <vector>

using namespace std;

int N, M, L;
int current = 1;
vector<int> num;
int answer;

void Input()
{
	cin >> N >> M >> L;
	num.resize(N+1);
}

void Solution()
{
	L = L % N;
	while (true)
	{

		num[current]++;
		if (num[current] == M)
			break;

		answer++;
		if (num[current] % 2 == 1)
		{
			current += L;
			if (current > N)
				current -= N;
		}
		else
		{
			current -= L;
			if (current < 1)
				current += N;
		}
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}