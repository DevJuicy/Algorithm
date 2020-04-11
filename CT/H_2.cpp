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
	// ù �����ϴ»���̸� Map�ڷᱸ���� K-1��ŭ ���ڸ� �ְ�
	// ù �����ϴ� ����� �ƴ϶�� ������ ����Ǿ��ִ� ������ 1�� ���� answer�� �߰��ϴ� ���


	// ù�����ϴ»���̶��
	if (remainCoupon.find(id) == remainCoupon.end())
	{
		// map �� k-1�� ��ŭ ���
		remainCoupon[id] = k - 1;
		answer++;
	}
	// ���������ִ� ������
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
		// ��ūȭ
		tokenizeList = Tokenize(id_list[i]);
		// �ߺ����� C++���
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