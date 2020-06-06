// https://hongku.tistory.com/149
#include <iostream>

using namespace std; 

int data[10] = {4, 1, 2, 3, 9, 7, 8, 6, 10, 5};

void quick_sort(int *data, int start, int end)
{
	if(start >= end)
		return; 

	int pivot = start;
	int i = pivot + 1;
	int j = end; 
	int temp;

	while(i <= j)
	{
		while(i <= end && data[i] <= data[pivot])
			i++;
		while(j > start && data[j] >= data[pivot])
			j--;

		if(i > j)
		{
			temp = data[j]; 
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			temp = data[i]; 
			data[i] = data[j];
			data[j] = temp;
		}
	}

	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main()
{
	int arr[8] = { 3,5,2,6,9,1,23,18 };
	quick_sort(arr, 0, 7);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << endl;
	return 0;
}

