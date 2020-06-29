#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node
{
public:
	int value;
	Node* left = NULL;
	Node* right = NULL;

	Node(int value)
	{
		this->value = value;
	}
};

class Tree
{
public:
	Node* root;
	Tree(int value)
	{
		Node* current = new Node(value);
		this->root = current;
	}

	void Push(int value)
	{
		if (root->value > value)
		{
			if (root->left == NULL)
			{
				Node* current = new Node(value);
				root->left = current;
			}
			else
			{
				Push(root->left, value);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				Node* current = new Node(value);
				root->right = current;
			}
			else
			{
				Push(root->right, value);
			}
		}
	}

	void Push(Node* parent, int value)
	{
		if (parent->value > value)
		{
			if (parent->left == NULL)
			{
				Node* current = new Node(value);
				parent->left = current;
			}
			else
			{
				Push(parent->left, value);
			}
		}
		else
		{
			if (parent->right == NULL)
			{
				Node* current = new Node(value);
				parent->right = current;
			}
			else
			{
				Push(parent->right, value);
			}
		}
	}

	void Visit(Node* current)
	{
		cout << current->value << endl;
	}

	void PreOrder(Node* current)
	{
		if (current != NULL)
		{
			Visit(current);
			PreOrder(current->left);
			PreOrder(current->right);
		}
	}

	void InOrder(Node* current)
	{
		if (current != NULL)
		{
			InOrder(current->left);
			Visit(current);
			InOrder(current->right);
		}
	}

	void PostOreder(Node* current)
	{
		if (current != NULL)
		{
			PostOreder(current->left);
			PostOreder(current->right);
			Visit(current);
		}
	}
};

int main()
{
	Tree tree(5);
	tree.Push(3);
	tree.Push(8);
	tree.Push(4);
	tree.Push(1);
	tree.Push(9);
	tree.Push(11);

	tree.PreOrder(tree.root);
	cout << endl;
	tree.InOrder(tree.root);
	cout << endl;
	tree.PostOreder(tree.root);
	cout << endl;
}