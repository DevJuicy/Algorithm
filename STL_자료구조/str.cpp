#include <iostream>
#include <vector>
#include <string>
#include<sstream>
using namespace std;

#pragma region Token
void comma()
{
	string str;
	getline(cin, str);
	string token;
	stringstream ss(str);

	while (getline(ss, token, ','))
	{
		cout << token << endl;
	}
}
void Default()
{
	string line;
	string token;

	getline(cin, line);

	stringstream ss(line);
	while (ss >> token)
	{
		cout << token << endl;
	}
}

#pragma endregion

#pragma region IsString
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
#pragma endregion

#pragma region Parse
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

#pragma endregion

int main()
{

}