#include <iostream>
#include <vector>

using namespace std;
string first, second;

void Input()
{
	cin >> first >> second;
}

int Solution()
{
	int comp = second.size() - first.size()+1;
	int min = 999999;
	for (int i = 0; i < comp; i++)
	{
		int current = 0;
		for (int j = 0; j < first.size(); j++)
		{
			if (first[j] != second[j+i])
				current++;
		}
		if (current < min) min = current;
	}
	return min;
}

int main()
{
	Input();
	cout << Solution();
}