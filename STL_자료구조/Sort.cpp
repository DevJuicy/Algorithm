#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;
vector<pair<int, int>> pVector;

bool Compare(int a, int b)
{
	return a > b; // 6 5 2 1
	// return a < b // 1 2 5 6
}

void NormalSort()
{
	sort(a.begin(), a.end(), less<int>()); // 1 2 5 6
	// greater<int>() // 6 5 2 1

	// 중복제거
	a.erase(unique(a.begin(), a.end()), a.end());
}

void CustomSort()
{
	sort(a.begin(), a.end(), Compare);
}

bool PairCompare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second; // second 오름차순
	return a.first < b.first; // first 오름차순
}

void PairSort()
{
	// 디폴트는 first 오름차순
	sort(pVector.begin(), pVector.end(), PairCompare);
}

int main()
{
	// 퀵소트 sort
	// 머지소트 stable_sort
	// 힙소트 sort_heap
}