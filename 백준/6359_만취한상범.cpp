#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int arr[101];

int solution(int N)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 1)
			cnt++;
	}
	return cnt;
}

int main()
{
	int T;
	vector<int> answer;

	cin >> T;


	// 제곱수는 1로 처음에 만들어줬음
	// 다른방법으로 sqrt()써서 그 값의 제곱이 현재값이랑 같은지 비교해도되지만 엄청느리겠지?
	for (int i = 1; i <= 10; i++)
	{
		arr[i * i] = 1;
	}

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		answer.push_back(solution(N));
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
}