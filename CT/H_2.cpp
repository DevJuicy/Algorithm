#include <iostream>
#include <vector>
#include <algorithm>
#include<sstream>
#include <map>
using namespace std;

map<string, int> remainCoupon;
int answer = 0;

vector<string> Tokenize(string ids)
{
	vector<string> tokenizeList;
	string token;
	stringstream ss(ids);
	while (ss >> token)
	{
		tokenizeList.push_back(token);
	}
	return tokenizeList;
}

void EraseOverlap(vector<string>& tokenizeList)
{
	sort(tokenizeList.begin(), tokenizeList.end());
	tokenizeList.erase(unique(tokenizeList.begin(), tokenizeList.end()), tokenizeList.end());
}

void Buy(string id, int k)
{
	// 첫 구매하는사람이면 Map자료구조에 K-1만큼 숫자를 넣고
	// 첫 구매하는 사람이 아니라면 이전에 저장되어있는 값에서 1씩 빼서 answer에 추가하는 방식


	// 첫구매하는사람이라면
	if (remainCoupon.find(id) == remainCoupon.end())
	{
		// map 에 k-1개 만큼 등록
		remainCoupon[id] = k - 1;
		answer++;
	}
	// 구매한적있는 사람라면
	else
	{
		if (remainCoupon[id] == 0)
			return;
		remainCoupon[id]--;
		answer++;
	}
}

int solution(vector<string>id_list, int k)
{
	for (int i = 0; i < id_list.size(); i++)
	{
		vector<string> tokenizeList;
		// 토큰화
		tokenizeList = Tokenize(id_list[i]);
		// 중복제거 C++기능
		EraseOverlap(tokenizeList);

		for (int j = 0; j < tokenizeList.size(); j++)
		{
			Buy(tokenizeList[j], k);
		}
	}

	return answer;
}

int main()
{
	//cout << solution({ "A B C D", "A D", "A B D", "B D" }, 2) << endl;
	//cout << solution({ "JAY", "JAY ELLE JAY MAY", "MAY ELLE MAY", "ELLE MAY", "ELLE ELLE ELLE", "MAY" }, 3);
}