#include <string>
#include <vector>
#include <iostream>
using namespace std;

int MinusSolution(string strNum)
{
	for (int i = 1; i < strNum.size(); i++)
	{
		if (strNum[i] < '5')
			continue;

		// string�� '5' �߰��ϱ�
		strNum.insert(i, "5");

		// string -> int
		return stoi(strNum);
	}
}

int PlusSolution(string strNum)
{
	for (int i = 0; i < strNum.size(); i++)
	{
		if (strNum[i] > '5')
			continue;

		// string�� '5' �߰��ϱ�
		strNum.insert(i, "5");

		// string -> int
		return stoi(strNum);
	}
}

int solution(int n)
{
	int answer = 0;
	string strNum = to_string(n); // int -> string ��ȯ

	if (n >= 0)
		answer = PlusSolution(strNum);
	else
		answer = MinusSolution(strNum);

	return answer;
}

int main()
{
	cout << solution(-999);
}
