#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// ���� C++�� ��ũ������� JAVA�� ��ũ������ �˾Ƽ� �ϱ�
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
	// ' '�� ������ ��ũ�������ؼ� ����
	vector<string> vec = Tokenize(str);
	int pointerCount = 0;
	int value;

	int startingPointer = vec[0][0] - '0';

	while (true)
	{
		// �ּҰ� ����ִ� ���
		if (vec[startingPointer + 1][0] == '0')
		{
			// string�� int�� �ٲ��ִ� �Լ� JAVA���� �˾Ƽ� ����
			startingPointer = stoi(vec[startingPointer + 2]);
			pointerCount++;
		}
		// ���� ����ִ� ���
		else
		{
			// string�� int�� �ٲ��ִ� �Լ� JAVA���� �˾Ƽ� ����
			value = stoi(vec[startingPointer + 2]);
			break;
		}
	}

	string answer = "0;";
	for (int i = 1; i <= pointerCount; i++)
	{
		answer += " 0 ";

		// int�� string�� �ٲ��ִ� �Լ� JAVA���� �˾Ƽ� ����
		answer += to_string(i * 2);
	}

	answer += " 1 ";
	// int�� string�� �ٲ��ִ� �Լ� JAVA���� �˾Ƽ� ����
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