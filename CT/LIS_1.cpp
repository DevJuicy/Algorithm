#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, bool> stairs;
int lastStair;
bool answer;
void DFS(int current, int k)
{
    cout << current << endl;
    if (current == lastStair)
    {
        answer = true;
        return;
    }
    if (k == 0)
        return;

    if (stairs[current + k + 1])
        DFS(current + k + 1, k + 1);
    if (stairs[current + k])
        DFS(current + k, k);
    if (stairs[current + k - 1])
        DFS(current + k - 1, k - 1);
}

bool solution(vector<int> stones)
{
    for (int i = 0; i < stones.size(); i++)
        stairs[stones[i]] = true;
    lastStair = stones[stones.size() - 1];
    DFS(1,1);
    return answer;
}

int main()
{
    cout << solution({ 0,1,2,3,4,8,9,11 });
}