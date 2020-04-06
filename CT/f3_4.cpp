#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, bool> visited;
map<string, int> acc;
bool overlap[100001];

int ParseToInt(string str)
{
	int answer = stoi(str);
	return answer;
}

string ParseToString(int a)
{
	string answer = to_string(a);
	return answer;
}

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions)
{
	vector<vector<string>> answer;

	// 중복인경우 해당 인덱스 true
	for (int i = 0; i < transactions.size(); i++)
	{
		if (visited.find(transactions[i][0]) == visited.end())
			visited[transactions[i][0]] = true;
		else
			overlap[i] = true;
	}

	for (int i = 0; i < transactions.size(); i++)
	{
		if (overlap[i])
			continue;

		if (acc.find(transactions[i][2]) == acc.end())
		{
			if (transactions[i][1] == "SAVE")
				acc[transactions[i][2]] = ParseToInt(transactions[i][3]);
			else
				acc[transactions[i][2]] = -1 * ParseToInt(transactions[i][3]);
		}
		else
		{
			if (transactions[i][1] == "SAVE")
				acc[transactions[i][2]] += ParseToInt(transactions[i][3]);
			else
				acc[transactions[i][2]] -= ParseToInt(transactions[i][3]);
		}
	}

	for (int i = 0; i < snapshots.size(); i++)
		acc[snapshots[i][0]] += ParseToInt(snapshots[i][1]);

	for (auto it = acc.begin(); it != acc.end(); it++)
		answer.push_back({ it->first,ParseToString(it->second)});

	return answer;
}

int main()
{
	solution({ {"ACCOUNT1","100"},{"ACCOUNT2","150"} },
		{ {"1", "SAVE", "ACCOUNT2", "100"}
		,{"2", "WITHDRAW", "ACCOUNT1", "50"}
		,{"1", "SAVE", "ACCOUNT2", "100"}
		,{"4", "SAVE", "ACCOUNT3", "500"}
		,{"3", "WITHDRAW", "ACCOUNT2", "30"} });
}


// 계좌이름 / 잔액
// ID / 종류 / 계좌이름 / 출금금액