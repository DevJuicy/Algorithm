#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool IsCrossAble(int n, vector<int>& stones, int k)
{
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] <= n)
            cnt++;
        else
            cnt = 0;

        if (cnt >= k)
            return true;
    }
    return false;
}


int solution(vector<int> stones, int k)
{
    int min, max;
    min = 1;
    max = *max_element(stones.begin(), stones.end());

    while (min <= max)
    {
        int mid = (min + max) / 2;

        if (IsCrossAble(mid, stones, k))
            max = mid - 1;
        else
            min = mid + 1;
    }
    return min;
}

int main()
{
    cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
}