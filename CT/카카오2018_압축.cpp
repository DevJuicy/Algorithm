#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

void InitMap()
{
	char c = 'A';
	for (int i = 0; i < 26; i++)
	{
		string temp = "";
		temp += c + i;
		m[temp] = i + 1;
	}
}

vector<int> solution(string msg)
{
	vector<int> answer;
	InitMap();

	int lastMapIndex = 27;
	for (int i = 0; i < msg.size(); i++)
	{
		string currentC = "";
		currentC += msg[i];

		string nextC = currentC;
		int findIndex = 1;

		while (true)
		{
			nextC += msg[i + findIndex];

			if (m.find(nextC) == m.end())
			{
				m[nextC] = lastMapIndex;
				lastMapIndex++;
				answer.push_back(m[currentC]);
				i += findIndex - 1;
				break;
			}

			if (i + findIndex >= msg.size())
			{
				answer.push_back(m[currentC]);
				break;
			}

			currentC = nextC;
			findIndex++;
		}
	}

	return answer;
}

int main()
{
	//solution("KAKAO");
	//solution("TOBEORNOTTOBEORTOBEORNO");
	solution("ABABABABABABABAB");
}