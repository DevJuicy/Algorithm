#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue<pair<int, int>> pairPQ;
vector<int> days;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        days.push_back(temp);
        pairPQ.push({ temp,i });
    }
}

void Solution()
{
    int money = 0;
    int coinCount = 0;
    int i = 0;

    while (true)
    {
        int maxIndex = pairPQ.top().second;
        pairPQ.pop();

        if (i == maxIndex)
            break;

        for (; i < maxIndex; i++)
        {
            money -= days[i];
            coinCount++;
        }
        money += coinCount * days[maxIndex] - 1;
        i++;
        coinCount = 0;

        if (i >= days.size() - 1)
            break;
    }
    cout << money;
}

int main()
{
    Input();
    Solution();
}