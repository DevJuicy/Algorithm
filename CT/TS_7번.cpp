#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// 여긴 C++용 토크나이즈라 JAVA용 토크나이즈 알아서 하길
vector<string> Tokenize(string ids)
{
	vector<string> tokenizeList;
	string token;
	stringstream ss(ids);
	while (ss >> token)
	{
		tokenizeList.push_back(token);
	}
	return tokenizeList;
}

string solution(string str)
{
	// ' '를 단위로 토크나이즈해서 빼옴
	vector<string> vec = Tokenize(str);
	int pointerCount = 0;
	int value;

	int startingPointer = vec[0][0] - '0';

	while (true)
	{
		// 주소가 담겨있는 경우
		if (vec[startingPointer + 1][0] == '0')
		{
			// string을 int로 바꿔주는 함수 JAVA껄로 알아서 쓰셈
			startingPointer = stoi(vec[startingPointer + 2]);
			pointerCount++;
		}
		// 값이 담겨있는 경우
		else
		{
			// string을 int로 바꿔주는 함수 JAVA껄로 알아서 쓰셈
			value = stoi(vec[startingPointer + 2]);
			break;
		}
	}

	string answer = "0;";
	for (int i = 1; i <= pointerCount; i++)
	{
		answer += " 0 ";

		// int를 string로 바꿔주는 함수 JAVA껄로 알아서 쓰셈
		answer += to_string(i * 2);
	}

	answer += " 1 ";
	// int를 string로 바꿔주는 함수 JAVA껄로 알아서 쓰셈
	answer += to_string(value);

	int emptySize = 3 - pointerCount;

	for (int i = 0; i < emptySize; i++)
	{
		answer += " 0 0";
	}
	return answer;
}


int main()
{
	cout << solution("4; 1 30 0 6 0 2 1 3");
}