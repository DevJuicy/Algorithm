#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
	int parentIndex;
	vector<int> childrenIndex;
	queue<int> childQueue;

	int key = -1;
	bool visit = false;
	bool lock = false;
};

vector<Node> tree;
vector<int> visitCheck;
map<int, bool> m;

void MakeLock(vector<vector<int>>& order);

void MakeTree(vector<vector<int>>& path);

void DFS(int current);

void InitParentVisit(int current);

bool CheckAllVisited();

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order)
{
	m[0] = true;
	tree.resize(n);
	tree[0].parentIndex = -1;
	visitCheck.resize(n);

	MakeTree(path);
	MakeLock(order);
	DFS(0);

	return CheckAllVisited();
}

void MakeTree(vector<vector<int>>& path)
{
	for (int i = 0; i < path.size(); i++)
	{
		int firstNum = path[i][0];
		int secondNum = path[i][1];

		if (m[firstNum])
		{
			tree[firstNum].childrenIndex.push_back(secondNum);
			tree[secondNum].parentIndex = firstNum;
			m[secondNum] = true;
		}
		else
		{
			tree[secondNum].childrenIndex.push_back(firstNum);
			tree[firstNum].parentIndex = secondNum;
			m[firstNum] = true;
		}
	}
}

void MakeLock(vector<vector<int>>& order)
{
	for (int i = 0; i < order.size(); i++)
	{
		tree[order[i][0]].key = order[i][1];
		tree[order[i][1]].lock = true;
	}
}

void DFS(int current)
{
	tree[current].visit = true;
	visitCheck[current] = true;

	if (tree[current].key != -1) // 현재 노드가 Key를 가진경우
	{
		tree[tree[current].key].lock = false; // 락 해제시켜주고
		InitParentVisit(tree[current].key);// visit 재귀로 열어주기
	}

	for (int i = 0; i < tree[current].childrenIndex.size(); i++)
	{
		int child = tree[current].childrenIndex[i];

		if (tree[child].lock || tree[child].visit) // 이미 방문한 녀석이거나 잠겨져있는곳이라면 무시
			continue;
		tree[current].childQueue.push(child);
	}

	while (!tree[current].childQueue.empty())
	{
		int child = tree[current].childQueue.front();
		tree[current].childQueue.pop();

		DFS(child);
	}
}

void InitParentVisit(int current)
{
	int parent = tree[current].parentIndex;

	if (parent == -1)
		return;

	if (tree[parent].lock)
		return;

	tree[parent].childQueue.push(current);
	tree[parent].visit = false;
	InitParentVisit(parent);
}

bool CheckAllVisited()
{
	for (int i = 0; i < visitCheck.size(); i++)
	{
		if (visitCheck[i] == false)
			return false;
	}
	return true;
}


int main()
{
	bool answer = 
	solution(
		9,
		{ {0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5} }
		, { {8,5},{6,7},{4,1} }
	);
	//solution(
	//	9,
	//	{ {0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5} }
	//	, { {4,1},{5,2}}
	//);
	//solution(
	//	9,
	//	{ {0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5} }
	//	, { {8,7},{6,5},{4,1} }
	//);

	if (answer)
		cout << "TRUE";
	else
		cout << "FALSE";
}