#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> preOrder;
vector<int> postOrder;
vector<int >inOrder;

class Node
{
public:
	int value;
	int x;
	int y;
	Node* left = NULL;
	Node* right = NULL;

	Node(int x, int y, int value)
	{
		this->x = x;
		this->y = y;
		this->value = value;
	}
};

class Tree
{
public:
	Node* root;
	Tree(Node* root)
	{
		this->root = root;
	}

	void Push(Node* parent, Node* current)
	{
		if (parent->x > current->x)
		{
			if (parent->left == NULL)
				parent->left = current;
			else
			{
				Push(parent->left, current);
			}
		}

		else if (parent->x < current->x)
		{
			if (parent->right == NULL)
				parent->right = current;
			else
			{
				Push(parent->right, current);
			}
		}
	}

	void Visit(Node* current, vector<int>& order)
	{
		order.push_back(current->value);
	}

	void PreOrder(Node* current)
	{
		if (current != NULL)
		{
			Visit(current, preOrder);
			PreOrder(current->left);
			PreOrder(current->right);
		}
	}

	void InOrder(Node* current)
	{
		if (current != NULL)
		{
			InOrder(current->left);
			Visit(current, preOrder);
			InOrder(current->right);
		}
	}

	void PostOrder(Node* current)
	{
		if (current != NULL)
		{
			PostOrder(current->left);
			PostOrder(current->right);
			Visit(current, postOrder);
		}
	}
};

bool Compare(vector<int> a, vector<int> b)
{
	if (a[1] == b[1])
		return a[0] < b[0];
	return a[1] > b[1];
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;
	for (int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1);
	sort(nodeinfo.begin(), nodeinfo.end(), Compare);

	Node* root = new Node(nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2]);
	Tree* tree = new Tree(root);

	for (int i = 1; i < nodeinfo.size(); i++)
	{
		Node* currnet = new Node(nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]);
		tree->Push(root, currnet);
	}

	tree->PreOrder(root);
	tree->PostOrder(root);
	answer.push_back(preOrder);
	answer.push_back(postOrder);

	return answer;
}

int main()
{
	solution({ {5,3} ,{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
}