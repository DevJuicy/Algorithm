#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Num
{
	int index;
	int count;
	long long value;
};

struct Compare
{
	bool operator()(Num t, Num u)
	{
		return t.value > u.value;
	}
};

long long solution(int n)
{
	if (n == 1)
	{
		return 1;
	}

	Num two;
	two.index = 2;
	two.count = 2;
	two.value = 4;

	priority_queue<Num, vector<Num>, Compare> pq;

	pq.push(two);

	int index = 2;
	int count = 1;
	long max = 0;

	while (true)
	{
		Num temp = pq.top();
		pq.pop();
		if (temp.value != max)
		{
			count++;
			max = temp.value;
		}
		if (count == n)
		{
			return temp.value;
		}

		temp.count++;
		temp.value = (long long)pow(temp.index, temp.count);
		pq.push(temp);

		if (index == temp.index)
		{
			Num num;
			num.index = ++index;
			num.count = 2;
			num.value = (long long)pow(num.index, num.count);
			pq.push(num);
		}
	}
}

int main()
{
	cout << solution(4);
}