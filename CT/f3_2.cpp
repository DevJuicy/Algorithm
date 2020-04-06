#include <iostream>
#include <vector>

using namespace std;

int FindCheat(string a, string b, string answer_sheet)
{
	int xNumber = 0;
	int seq = 0;
	vector<int> vSeq;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[i] && a[i] != answer_sheet[i])
		{
			xNumber++;
			seq++;
			if(i=a.size()-1)
				vSeq.push_back(seq);
		}
		else
		{
			vSeq.push_back(seq);
			seq = 0;
		}
	}

	int maxSeq = 0;
	for (int i = 0; i < vSeq.size(); i++)
	{
		if (maxSeq < vSeq[i])
			maxSeq = vSeq[i];
	}
	return xNumber + (maxSeq * maxSeq);
}


int Solution(string answer_sheet ,vector<string> sheets)
{
	int maxValue = 0;
	for (int i = 0; i < sheets.size()-1; i++)
	{
		for (int j = i + 1; j < sheets.size(); j++)
		{
			int current = FindCheat(sheets[i], sheets[j], answer_sheet);
			if (current > maxValue)
				maxValue = current;
		}
	}
	return maxValue;
}

int main()
{
	cout << Solution({ "24551" }, { "24553","24553","24553","24553" });
}