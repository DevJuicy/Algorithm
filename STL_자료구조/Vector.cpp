#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> arr(6, vector<int>(5, 0)); // arr[6][5] ����
vector<vector<int>> adList(1001);

void Erase()
{
	arr.erase(arr.begin() + 3); // 3���ε�������
	arr.erase(arr.begin() + 3, arr.begin() + 5 + 1); // 3~5���� ����
}

void SameErase()
{
	vector<string> str;
	str = { "abc","asc","abc","asc","bsc","abc" };
	// �ߺ����Ŵ� �ݵ�� ������ �Ŀ� ����ؾ���
	str.erase(unique(str.begin(), str.end()), str.end());
}

int main()
{

}