#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector < vector<int >> key1;
vector < vector<int >> key2;
vector < vector<int >> key3;
vector < vector<int >> key4;

void DEBUG(vector<vector<int>> vec)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool IsRightKey(vector<vector<int>> lock)
{
	for (int i = 0; i < lock.size(); i++)
	{
		for (int j = 0; j < lock[i].size(); j++)
		{
			if (lock[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool Compare(vector<vector<int>> key, vector<vector<int>> lock)
{
	if (IsRightKey(lock))
		return true;

	vector<pair<int, int>> keyInPosition;
	for (int i = 0; i < key.size(); i++)
	{
		for (int j = 0; j < key[i].size(); j++)
		{
			if (key[i][j] == 1)
				keyInPosition.push_back({ i,j });
		}
	}

	for (int i = 0; i < lock.size(); i++)
	{
		for (int j = 0; j < lock[i].size(); j++)
		{
			if (lock[i][j] == 1)
				continue;
			// 1,2 ¿Ó¼·


			for (int k = 0; k < keyInPosition.size(); k++)
			{
				vector<vector<int>> tempLock = lock;
				// 1,0
				int yWeight = i - keyInPosition[k].first; //0
				int xWieght = j - keyInPosition[k].second; //2


				bool isCandidateBlock = true;
				for (int m = 0; m < keyInPosition.size(); m++)
				{
					int currentPositionY = keyInPosition[m].first + yWeight;
					int currentPositionX = keyInPosition[m].second + xWieght;

					if (currentPositionY < tempLock.size() && currentPositionX < tempLock.size())
					{
						if (tempLock[currentPositionY][currentPositionX] == 1)
						{
							isCandidateBlock = false;
							break;
						}
						else
						{
							tempLock[currentPositionY][currentPositionX] = 1;
						}
					}
				}

				if (!isCandidateBlock)
					continue;

				if (IsRightKey(tempLock))
					return true;
			}
		}
	}
	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	int keySize = key.size();
	key1 = key;

	for (int i = keySize - 1; i >= 0; i--)
	{
		vector<int> temp;
		for (int j = keySize - 1; j >= 0; j--)
		{
			temp.push_back(key[i][j]);
		}
		key2.push_back(temp);
	}
	for (int i = 0; i < keySize; i++)
	{
		vector<int> temp;
		for (int j = keySize - 1; j >= 0; j--)
		{
			temp.push_back(key[j][i]);
		}
		key3.push_back(temp);
	}
	for (int i = keySize - 1; i >= 0; i--)
	{
		vector<int> temp;
		for (int j = 0; j < keySize; j++)
		{
			temp.push_back(key[j][i]);
		}
		key4.push_back(temp);
	}

	bool answer = Compare(key1,lock) + Compare(key2, lock)
		+ Compare(key3, lock) + Compare(key4, lock);

	return answer;
}

int main()
{
	cout << solution({
			{0, 0, 0}, {0, 0, 0}, {0, 0, 0} },
		{ {1, 1, 1}, {1, 1, 1}, {1, 1, 1} });
}