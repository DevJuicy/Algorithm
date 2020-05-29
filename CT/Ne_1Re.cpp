#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool FindTriangle(int index, vector<int>& vote)
{
	if (vote[vote[vote[index] - 1] - 1] == index + 1)
		return true;
	return false;
}

int solution(vector<int> vote)
{
	int answer = 0;
	for (int i = 0; i < vote.size(); i++)
	{
		if (FindTriangle(i, vote))
			answer++;
	}
	return answer / 3;
}

int main()
{
	cout << solution({ 2,3,1,3,4 }) << endl;
	cout << solution({ 5,4,2,3,1 }) << endl;
	cout << solution({ 2,3,4,1,6,7,5 }) << endl;
}