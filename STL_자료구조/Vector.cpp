#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> arr(6, vector<int>(5, 0)); // arr[6][5] 선언
vector<vector<int>> adList(1001);

void Erase()
{
	arr.erase(arr.begin() + 3); // 3번인덱스삭제
	arr.erase(arr.begin() + 3, arr.begin() + 5 + 1); // 3~5까지 삭제
}

void SameErase()
{
	vector<string> str;
	str = { "abc","asc","abc","asc","bsc","abc" };
	// 중복제거는 반드시 정렬한 후에 사용해야함
	str.erase(unique(str.begin(), str.end()), str.end());
}

int main()
{

}