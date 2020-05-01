#include <iostream>
#include <vector>
using namespace std;


class Block
{
public :
	int* point[4];
	Block(int* p0, int* p1, int* p2, int* p3)
	{
		point[0] = p0;
		point[1] = p1;
		point[2] = p2;
		point[3] = p3;
	}
};

vector<Block> blocks;

void Hello(int* p)
{
	//int a = 5;
	//p = &a;
	(*p)++;
}

void Address(int& a) // 변수 자체 넘기기
{
	a = 5;
	cout << a;
}

int main()
{
	int* p;
	int a = 1;
	p = &a;

	int arr[] = { 1,2,3,4 };

	//Address(a);

	blocks.push_back(Block(&arr[0], &arr[1], &arr[2], &arr[3]));
	Hello(arr);
}