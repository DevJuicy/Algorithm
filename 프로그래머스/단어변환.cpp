#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> node;
vector<bool> visited;
queue<int> Q;

int Compare(string a, string b)
{
	int diffent = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			diffent++;
	}
	return diffent;
}

int BFS(int startIndex, string target, vector<string>& words)
{
	visited[startIndex] = true;
	Q.push(startIndex);
	int depth = 0;

	while (true)
	{
		depth++;
		vector<int> buffer;
		while (!Q.empty())
		{
			int currentIndex = Q.front();

			Q.pop();

			for (int i = 0; i < node[currentIndex].size(); i++)
			{
				if (words[node[currentIndex][i]] == target)
					return depth;

				if (!visited[node[currentIndex][i]])
				{
					visited[node[currentIndex][i]] = true;
					buffer.push_back(node[currentIndex][i]);
				}
			}
		}

		for (int i = 0; i < buffer.size(); i++)
		{
			for (int j = 0; j < node[buffer[i]].size(); j++)
			{
				if (words[node[buffer[i]][j]] == target)
					return depth + 2;

				if (!visited[node[buffer[i]][j]])
				{
					visited[node[buffer[i]][j]] = true;
					Q.push(node[buffer[i]][j]);
				}
			}
		}
		if (buffer.size() == 0)
			return 0;
	}
}

int solution(string begin, string target, vector<string> words)
{
	int answer = 0;
	words.push_back(begin);
	node.resize(words.size());
	visited.resize(words.size());
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words.size(); j++)
		{
			if (i == j)
				continue;

			if (Compare(words[i], words[j]) == 1)
				node[i].push_back(j);
		}
	}

	answer = BFS(words.size() - 1, target, words);

	return answer;
}

int main()
{

	cout  << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
	cout << solution("hot", "lot", { "dot", "dog", "lot", "log" });
	cout << solution("hit", "wow", { "hot", "dot", "dog", "lot", "log", "cog", "wow" });
}