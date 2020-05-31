#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> numberList;
vector<char> operatorList;

int OperateNumber(long long a, long long b, char oper)
{
	if (oper == '*')
		return a * b;
	else if (oper == '+')
		return a + b;
	return a - b;
}

void OperateCase(vector<long long>& tempNumberList, vector<char>& tempOperatorList, char oper)
{
	for (int i = 0; i < tempOperatorList.size(); i++)
	{
		if (tempOperatorList[i] == oper)
		{
			tempNumberList[i] = OperateNumber(tempNumberList[i], tempNumberList[i + 1], tempOperatorList[i]);
			tempNumberList.erase(tempNumberList.begin() + i + 1);
			tempOperatorList.erase(tempOperatorList.begin() + i);
			i--;
		}
	}
}

long long PriorityOperate(char first, char second, char third)
{
	vector<long long> tempNumberList = numberList;
	vector<char> tempOperatorList = operatorList;
	OperateCase(tempNumberList, tempOperatorList, first);
	OperateCase(tempNumberList, tempOperatorList, second);
	OperateCase(tempNumberList, tempOperatorList, third);

	return abs(tempNumberList[0]);
}

int ParseToInt(string str)
{
	int answer = stoi(str);
	return answer;
}

void ExtractNumber(string expenssion)
{
	string current = "";
	for (int i = 0; i < expenssion.size(); i++)
	{
		if (expenssion[i] == '+' || expenssion[i] == '-' || expenssion[i] == '*')
		{
			operatorList.push_back(expenssion[i]);
			numberList.push_back(ParseToInt(current));
			current = "";
			continue;
		}
		current.push_back(expenssion[i]);
	}
	numberList.push_back(ParseToInt(current));
}

long long solution(string expression)
{
	long long answer = 0;
	vector<long long> answerCandidate;
	ExtractNumber(expression);
	answerCandidate.push_back(PriorityOperate('*', '+', '-'));
	answerCandidate.push_back(PriorityOperate('*', '-', '+'));
	answerCandidate.push_back(PriorityOperate('+', '*', '-'));
	answerCandidate.push_back(PriorityOperate('+', '-', '*'));
	answerCandidate.push_back(PriorityOperate('-', '+', '*'));
	answerCandidate.push_back(PriorityOperate('-', '*', '+'));
	sort(answerCandidate.begin(), answerCandidate.end());

	return answerCandidate[answerCandidate.size()-1];
}

int main()
{
	cout << solution("100-200*300-500+20") << endl;
	//cout << solution("50*6-3*2") << endl;
}