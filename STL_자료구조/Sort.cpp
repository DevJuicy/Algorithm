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

	// �ߺ�����
	a.erase(unique(a.begin(), a.end()), a.end());
}

void CustomSort()
{
	sort(a.begin(), a.end(), Compare);
}

bool PairCompare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second; // second ��������
	return a.first < b.first; // first ��������
}

void PairSort()
{
	// ����Ʈ�� first ��������
	sort(pVector.begin(), pVector.end(), PairCompare);
}

int main()
{
	// ����Ʈ sort
	// ������Ʈ stable_sort
	// ����Ʈ sort_heap
}