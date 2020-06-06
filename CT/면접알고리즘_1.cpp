#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Swap(vector<string>& arr, int a, int b)
{
	string temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

bool IsBig(string a, string b)
{
	int lowSize = a.size() > b.size() ? b.size() : a.size();

	for (int i = 0; i < lowSize; i++)
	{
		if (a[i] > b[i])
		{
			return true;
		}
		else if (a[i] < b[i])
		{
			return false;
		}
	}

	return a.size() > b.size() ? true : false;
}

string Lower(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 'a' - 'A';
	}
	return a;
}


void QuickSort(vector<string>& data, int start, int end)
{
	int pivot = start;
	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		while (i <= end && !IsBig(Lower(data[i]), Lower(data[pivot])))
			i++;
		while (j > start && IsBig(Lower(data[j]), Lower(data[pivot])))
			j--;

		if (i > j)
		{
			Swap(data, pivot, j);
		}
		else
		{
			Swap(data, i, j);
		}
	}

	if (start < end)
	{
		QuickSort(data, start, j - 1);
		QuickSort(data, j + 1, end);
	}

}

int main()
{
	vector<string> dic;
	dic.push_back("Abc");
	dic.push_back("sky");
	dic.push_back("Skygroup");
	dic.push_back("apple");
	dic.push_back("Bare");
	dic.push_back("craze");
	dic.push_back("zebra");

	//sort(dic.begin(), dic.end());

	//for (int i = 0; i < dic.size(); i++)
	//{
	//	cout << dic[i] << endl;
	//}

	cout << endl;
	QuickSort(dic, 0, 6);

	for (int i = 0; i < 7; i++)
	{
		cout << dic[i] << endl;
	}
}