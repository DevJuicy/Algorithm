#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq; // 내림차순 디폴트
//priority_queue<int, vector<int>, greater<int>> pq; // 오름차순

//priority_queue<pair<int, int>> pairPQ;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pairPQ; // pair 오름차순

struct pqStruct
{
	int start;
	int end;
	int value;
};

struct cmp
{
	bool operator()(pqStruct t, pqStruct u)
	{
		return t.value < u.value;
	}
};

priority_queue<pqStruct, vector<pqStruct>, cmp> pqCustom;

void PQ()
{
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(9);
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}

void CustomPQ()
{
	pqStruct a;
	a.value = 5;
	pqStruct b;
	b.value = 2;
	pqStruct c;
	c.value = 7;

	pqCustom.push(a);
	pqCustom.push(b);
	pqCustom.push(c);

	while (!pqCustom.empty())
	{
		cout << pqCustom.top().value;
		pqCustom.pop();
	}
}

void PairPQ()
{
	pairPQ.push({ 2,3 });
	pairPQ.push({ 1,5 });
	pairPQ.push({ 2,4 });
	pairPQ.push({ 5,7 });
	pairPQ.push({ 5,1 });
	pairPQ.push({ 1,8 });
	pairPQ.push({ 7,3 });

	while (!pairPQ.empty())
	{
		cout << pairPQ.top().first << " / " << pairPQ.top().second << endl;
		pairPQ.pop();
	}
}

int main()
{


}
