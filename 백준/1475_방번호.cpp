#include <iostream>
#include <vector>

using namespace std;

string N;
int arr[10];
int answer;
void Input()
{
	cin >> N;
}

void Solution()
{
	for (int i = 0; i < N.size(); i++)
		arr[N[i] - '0']++;
	
	arr[6] = (arr[6] + arr[9] + 1) / 2;

	for (int i = 0; i < 9; i++)
	{
		if (answer < arr[i])
			answer = arr[i];
	}
}

int main()
{
	Input();
	Solution();
	cout << answer;
}