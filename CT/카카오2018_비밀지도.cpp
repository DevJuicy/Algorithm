#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string ParseToBinaryString(int n, int num) // size , 10Áø¼ö ¼ö
{
	string result;
	for (int i = n - 1; i >= 0; i--)
	{
		int value = num / pow(2, i);
		if (value == 1)
			result += '#';
		else
			result += ' ';
		num = num % (int)pow(2, i);
	}
	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;
	for (int i = 0; i < n; i++)
	{
		answer.push_back(ParseToBinaryString(n, arr1[i] | arr2[i]));
	}
	return answer;
}

int main()
{
	solution(5, { 9,20,28,18,11 }, { 30,1,21,17,28 });
}