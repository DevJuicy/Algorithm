#include <iostream>

using namespace std;

void Swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void MakeHeap(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int child = i;
		while (child > 0)
		{
			int root = (child - 1) / 2;
			if (arr[root] < arr[child])
			{
				Swap(arr, root, child);
			}
			child = root;
		}
	}
}

void HeapSort(int arr[], int n)
{
	for (int i = n; i >= 0; i--)
	{
		Swap(arr, 0, i);
		MakeHeap(arr, i);
	}
}

int main()
{
	int arr[8] = { 6,2,3,1,8,5,10,7 };
	MakeHeap(arr, 7);

	HeapSort(arr, 7);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
}