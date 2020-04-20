#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> words;

string Reverse(string str)
{
	reverse(str.begin(),str.end());
	return str;
}

void Tokenize(string input)
{
	string token;
	stringstream ss(input);
	while (ss >> token)
	{
		words.push_back(token);
	}
}

string Solution(string input)
{
	string answer = "";
	Tokenize(input);
	for (int i = 0; i < words.size(); i++)
	{
		answer +=  Reverse(words[i]) + " ";
	}
	return answer;
}

int main()
{
	cout << Solution("abc 123 apple");
}