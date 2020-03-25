#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int N, K;
vector<int> sencer;
vector<int> dist;
int answer;

void Input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		sencer.push_back(temp);
	}

	sort(sencer.begin(), sencer.end());
	sencer.erase(unique(sencer.begin(), sencer.end()), sencer.end());
}

void Solution()
{
	if (K > N)
		K = N;

	for (int i = 0; i < sencer.size() - 1; i++)
		dist.push_back(sencer[i + 1] - sencer[i]);
	
	sort(dist.begin(), dist.end());
	for (int i = 0; i < dist.size() - K + 1; i++)
		answer += dist[i];
}

int main()
{
	Input();
	Solution();
	cout << answer;
}