#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> number;
int seq;

void Input()
{
	int n;
	do
	{
		cin >> n;
		number.push_back(n);
	} while (getc(stdin) == ' ');
	cin >> seq;
}

void Solution()
{
	int currentSeq = 0;
	vector<int> current;
	sort(number.begin(), number.end());
	do {
		currentSeq++;
		if (currentSeq == seq)
		{
			for (int i = 0; i < number.size(); i++)
				current.push_back(number[i]);
			break;
		}
	} while (next_permutation(number.begin(), number.end()));

	for (int i = 0; i < current.size(); i++)
		cout << current[i];
}

int main()
{
	Input();
	Solution();
}