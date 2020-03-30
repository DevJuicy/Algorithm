#include <iostream>
#include <vector>

using namespace std;
string input;
int second;
string answer = "______________";
void Input()
{
	cin >> input;
	cin >> second;
}

void Solution()
{
	second %= 14 + input.size();
	input = "______________"+input+"______________";

	for (int i = 0; i < 14; i++)
		answer[i] = input[i + second];
}