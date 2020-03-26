#include <iostream>
#include <vector>

using namespace std;

int R, B;

void Input()
{
	cin >> R >> B;
}

void Solution()
{
	R -= 4;
	int h = 1;
	int w = 1;
	while (true)
	{
		if (2 * h * h - R * h + 2 * B == 0)
			break;
		h++;
	}
	w = B / h;
	cout << w + 2 << " " << h+1;
}

int main()
{
	Input();
	Solution();
}