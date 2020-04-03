#include <iostream>
#include <vector>

using namespace std;

int nResult = 0;

int FindNextHeight(int height, int currentIndex, vector<int>& heightList)
{
	for (int i = currentIndex + 1; i < heightList.size(); i++)
	{
		if (heightList[i] >= height)
			return i;
	}
	return 0;
}

void FillInWater(int  startIndex, int endIndex, vector<int>& heightList)
{
	int height = heightList[startIndex];
	for (int i = startIndex + 1; i < endIndex; i++)
	{
		nResult += height - heightList[i];
	}
}

int solution(vector<int> heightList)
{
	int height = 0;
	for (int i = 0; i < heightList.size() - 1; i++)
	{
		height = heightList[i];
		for (int j = i + 1; j < heightList.size(); j++)
		{
			if (heightList[i] < heightList[j])
				break;
			else if (heightList[i] > heightList[j])
			{
				//Find
				int nextIndex = FindNextHeight(height, j, heightList);
				if (nextIndex == 0)
				{
					i = heightList.size();
					break;
				}
				FillInWater(i, nextIndex, heightList);
				i = nextIndex - 1;
			}
		}
	}
	return nResult;
}

int main()
{
	cout << solution({ 1,4,3,2,1,1,0,0 });
}