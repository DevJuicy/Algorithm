#include <iostream>
#include  <vector>

using namespace std;

char result[1001];

string solution(int n, vector<vector<int>> delivery)
{
	string answer;
	for (int i = 0; i < delivery.size(); i++)
	{
		if (delivery[i][2] == 1)
		{
			result[delivery[i][0]] = 'O';
			result[delivery[i][1]] = 'O';
			delivery.erase(delivery.begin() + i);
		}
	}

	for (int i = 0; i < delivery.size(); i++)
	{
		if (result[delivery[i][0]] == 'O')
		{
			result[delivery[i][1]] = 'X';
		}

		if (result[delivery[i][1]] == 'O')
		{
			result[delivery[i][0]] = 'X';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (result[i] == NULL)
			answer.push_back('?');
		else
			answer.push_back(result[i]);
	}
	return answer;
}

int main()
{
	//cout << solution(6, { {1,3,1},{3,5,0},{5,4,0},{2,5,0} });
	cout << solution(7, { {5,6,0},{1,3,1},{1,5,0},{7,6,0},{3,7,1},{2,5,0} });
}