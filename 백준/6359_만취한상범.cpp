#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int arr[101];

int solution(int N)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 1)
			cnt++;
	}
	return cnt;
}

int main()
{
	int T;
	vector<int> answer;

	cin >> T;


	// �������� 1�� ó���� ���������
	// �ٸ�������� sqrt()�Ἥ �� ���� ������ ���簪�̶� ������ ���ص������� ��û��������?
	for (int i = 1; i <= 10; i++)
	{
		arr[i * i] = 1;
	}

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		answer.push_back(solution(N));
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
}