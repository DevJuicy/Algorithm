#include <iostream>
#include <vector>
#include <string>
#include<sstream>
using namespace std;

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
	//cin >> line;
	getline(cin, line); // ���鹮�� ������
	cout << line << endl;

	stringstream ss(line);
	while (ss >> token)
	{
		cout << token << endl;
	}
}

int main()
{
	comma();
}