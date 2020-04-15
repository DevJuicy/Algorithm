#include <iostream>
#include <vector>
using namespace std;



bool solution(int input)
{
	if (input < 0 || (input != 0 && input % 10 == 0))
	{
		return false;
	}
	int reverse = 0;
	int collectInput = input;

	while (input > 0)
	{
		int temp = input % 10;
		input /= 10;
		reverse *= 10;
		reverse += temp;
	}
	return reverse==collectInput;
}

int main()
{
	cout << solution(12345) << endl;
	cout << solution(-101) << endl;
	cout << solution(1221) << endl;
}