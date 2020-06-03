#include <iostream>

using namespace std;

int sorted[8];

void merge(int *data, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end)
	{
		if (data[i] <= data[j])
		{
			sorted[k] = data[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = data[j];
			j++;
			k++;
		}
	}

	if (i > mid)
	{
		for (int t = j; t <= end; t++)
		{
			sorted[k] = data[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = data[t];
			k++;
		}
	}

	for (int t = start; t <= end; t++)
	{
		data[t] = sorted[t];
	}
}

void merge_sort(int *data, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(data, start, mid);
		merge_sort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

int main()
{
	int arr[8] = { 3,5,2,6,9,1,23,18 };
	merge_sort(arr, 0, 7);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << endl;
	return 0;
}


