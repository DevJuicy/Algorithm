#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    queue <int> q;
    q.push(numbers[0]);
    q.push(-1*numbers[0]);

    for (int i = 1; i < numbers.size(); i++)
    {
        int qSize = q.size();
        for (int j = 0; j < qSize; j++)
        {
            int qCurrent = q.front();
            q.pop();
            q.push(qCurrent + numbers[i]);
            q.push(qCurrent - numbers[i]);
        }
    }

    while (!q.empty())
    {
        int result = q.front();
        q.pop();
        if (result == target)
            answer++;
    }

    return answer;
}

int main()
{
    cout << solution({ 1,1,1,1,1 }, 3);
}