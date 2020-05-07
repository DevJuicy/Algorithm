#include <cstring>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

vector<string> answer;
map<string, string> nickName;

vector<string> outputType;
vector<string> outputID;

void OutputMessages(int index)
{
	answer.push_back(nickName[outputID[index]] + outputType[index]);
}

void TakeMessages(vector<string> &tokenizeStr)
{
	if (tokenizeStr[0] == "Enter")
	{
		nickName[tokenizeStr[1]] = tokenizeStr[2];
		outputID.push_back(tokenizeStr[1]);
		outputType.push_back("님이 들어왔습니다.");
	}
	else 	if (tokenizeStr[0] == "Leave")
	{
		outputID.push_back(tokenizeStr[1]);
		outputType.push_back("님이 나갔습니다.");
	}
	else if (tokenizeStr[0] == "Change")
	{
		nickName[tokenizeStr[1]] = tokenizeStr[2];
	}
}

vector<string> Tokenize(string str)
{
	vector<string> input;
	string token;
	stringstream ss(str);
	while (ss >> token)
		input.push_back(token);
	return input;
}

vector<string> solution(vector<string> record)
{
	for (int i = 0; i < record.size(); i++)
	{
		vector<string> tokenizeStr = Tokenize(record[i]);
		TakeMessages(tokenizeStr);
	}

	for (int i = 0; i < outputID.size(); i++)
	{
		OutputMessages(i);
	}

	return answer;
}

int main()
{
	solution({
		"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan" });
}