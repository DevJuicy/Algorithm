#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
	int length = s.size();
	int minNum = s.size();

	for (int i = 0; i < length; i++)
	{
		int currentLength = i + 1;
		int result = s.length();
		vector<string> strVector;
		int tempNum = 0;
		for (int j = 0; j < length; j += i + 1)
		{
			strVector.push_back(s.substr(j, i + 1));
		}

		int sameNumber;

		for (int j = 0; j < strVector.size(); j += sameNumber)
		{
			sameNumber = 1;
			string copyString = s;
			for (int k = j + 1; k < strVector.size(); k++)
			{
				if (strVector[j] == strVector[k])
					sameNumber++;
				else
					break;
			}
			if (sameNumber > 1)
			{
				int length = sameNumber;
				int count = 0;
				while (length > 0)
				{
					count++;
					length /= 10;
				}

				result += count;
				result -= (currentLength * (sameNumber - 1));
			}
		}
		if (result < minNum)
		{
			minNum = result;
		}
	}
	return minNum;
}

int main()
{
	cout << solution("aaaaaa");
}