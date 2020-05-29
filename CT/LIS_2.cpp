#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<char> answer;

bool IsClose(char a)
{
    if (a == '}')
        return true;
    return false;
}

bool IsInteger(char a)
{
    if (a >= '0' && a <= '9')
        return true;
    return false;
}

bool IsCharacter(char a)
{
    if (a >= 'a' && a <= 'z')
        return true;
    return false;
}

string Search()
{
    string tempString="";
    while (!answer.empty())
    {
        char current = answer.front();
        answer.pop();

        if (IsCharacter(current))
        {
            tempString.push_back(current);
        }
        else if (IsInteger(current))
        {
            int cnt = current - '0';
            answer.pop();
            string temp = Search();
            string buffer = "";
            for (int i = 0; i < cnt; i++)
                buffer += temp;
            tempString += buffer;
        }
        else if (IsClose(current))
        {
            return tempString;
        }
    }
    return tempString;
}

string solution(string ecryptedString)
{
    for (int i = 0; i < ecryptedString.size(); i++)
        answer.push(ecryptedString[i]);
    return Search();
}

int main()
{
    cout << solution("abd2{ab}");
}