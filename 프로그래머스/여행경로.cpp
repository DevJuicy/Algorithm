#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<string> stk;
void DFS(string start, vector<vector<string>>& tickets)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == start)
        {
            string destination = tickets[i][1];
            tickets.erase(tickets.begin() + i);
            DFS(destination,tickets);
            i=0;
        }
    }
    stk.push(start);
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());
    DFS("4",tickets);

    vector<string> answer;
    while (!stk.empty())
    {
        string current = stk.top();
        answer.push_back(stk.top());
        stk.pop();
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];

    return answer;
}

int main()
{
    solution({ {"1", "3"},{"2", "1"},{"2","3"},{"3","1"}
        ,{"3","2"},{"4","1"},{"4","2"} });
}