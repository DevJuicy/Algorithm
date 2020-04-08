#include <iostream>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K)
{
	int answer = 0;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	int sum = 0;
	while (pq.top()<K)
	{
		if (pq.size() < 2)
			return -1;

		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		sum = first + second * 2;
		pq.push(sum);
		answer++;
	}

	return answer;
}

int main()
{
	cout << solution({ 1, 1, 3, 9, 10, 12 }, 7);
}