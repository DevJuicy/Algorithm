#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

class Directory
{
public:
	string name;
	vector<Directory*> childDir;
	Directory(string name)
	{
		this->name = name;
	}
	int FindChild(string name)
	{
		for (int i = 0; i < childDir.size(); i++)
		{
			if (childDir[i]->name == name || childDir[i]->name + " " == name)
				return i;
		}
		return -1;
	}
};

Directory* root;
Directory* buffer;
vector<string> answer;

queue<string> ParseToPath(string str)
{
	queue<string> ret;
	string token;
	stringstream ss(str);

	while (getline(ss, token, '/'))
	{
		ret.push(token);
	}
	return ret;
}

void PushData(Directory* parent, queue<string> path)
{
	if (path.empty())
		return;
	string current = path.front();
	path.pop();

	int childIndex = parent->FindChild(current);
	if (childIndex > -1)
		PushData(parent->childDir[childIndex], path);
	else
	{
		Directory* child = new Directory(current);
		parent->childDir.push_back(child);
	}
}

void PoPData(Directory* parent, queue<string> path)
{
	if (path.empty())
		return;
	string current = path.front();
	path.pop();
	int childIndex = parent->FindChild(current);

	if (!path.empty())
		PoPData(parent->childDir[childIndex], path);
	else
		parent->childDir.erase(parent->childDir.begin() + childIndex);
}

void PasteData(Directory* parent, queue<string> path)
{
	if (path.empty())
		return;
	string current = path.front();
	path.pop();
	int childIndex = parent->FindChild(current);

	if (!path.empty())
		PasteData(parent->childDir[childIndex], path);
	else
		parent->childDir[childIndex]->childDir.push_back(buffer);
}

void CopyData(Directory* parent, queue<string> path)
{
	if (path.empty())
		return;
	string current = path.front();
	path.pop();
	int childIndex = parent->FindChild(current);

	if (current[current.size() - 1] != ' ')
		CopyData(parent->childDir[childIndex], path);
	else
	{
		buffer = parent->childDir[childIndex];
		if (!path.empty())
			PasteData(root, path);
		else if (path.empty())
			root->childDir.push_back(buffer);
	}
}

void DFS(Directory* parent, string parentName)
{
	string current = parentName + "/" + parent->name;
	answer.push_back(current);

	for (int i = 0; i < parent->childDir.size(); i++)
	{
		DFS(parent->childDir[i], current);
	}
}

vector<string> Solution(vector<string> directory, vector<string> command)
{
	root = new Directory("/");

	// Input Directory
	for (int i = 1; i < directory.size(); i++)
	{
		queue<string> dirPath;
		dirPath = ParseToPath(directory[i]);
		dirPath.pop();
		PushData(root, dirPath);
	}

	// Input Command
	for (int i = 0; i < command.size(); i++)
	{
		queue<string> dirPath;
		dirPath = ParseToPath(command[i]);

		string cmd = dirPath.front();
		dirPath.pop();

		if (cmd == "mkdir ")
			PushData(root, dirPath);
		else if (cmd == "rm ")
			PoPData(root, dirPath);
		else if (cmd == "cp ")
			CopyData(root, dirPath);
	}

	answer.push_back("/");
	for (int i = 0; i < root->childDir.size(); i++)
		DFS(root->childDir[i], "");

	return answer;
}