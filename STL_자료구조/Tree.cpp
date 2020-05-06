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