#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(int N, vector<vector<int>> bus_stop)
{
	vector<vector<int>> dist;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
			temp.push_back(1202);

		dist.push_back(temp);
	}

	for (int i = 0; i < bus_stop.size(); i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int difference = abs(j - (bus_stop[i][0] - 1)) + abs(k - (bus_stop[i][1] - 1));;
				if (difference < dist[j][k])
					dist[j][k] = difference;
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	solution(3, { {1,2},{3,3} });
}