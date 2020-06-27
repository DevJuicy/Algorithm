#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> target, vector<vector<int>> positions)
{
    int answer = 0;
    for (int i = 1; i < target.size(); i++)
    {
        target[i] += target[i - 1];
    }
    for (int i = 0; i < target.size(); i++)
    {
        target[i] *= target[i];
    }
    for (int i = 0; i < positions.size(); i++)
    {
        int multiflePosition =
            (positions[i][0]) * (positions[i][0]) +
            (positions[i][1]) * (positions[i][1]);

        int score = 0;
        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] < multiflePosition)
                continue;

            score += 10 - 2 * i;
            break;
        }
        answer += score;
    }


    return answer;

}

int main()
{
    cout << solution({ 2,2,2,2,2 },
        { {0, 0} ,{0, 1},{1, 1},{-3, 5},{7,5},{10, 0},{-15, 22},{-6, -5},{3, 3},{5, -5} });
    //solution({ 2,3,4,3,2 }, 
    //    { {0, 0} ,{0, 1},{1, 1},{-3, 5},{7,5},{10, 0},{-15, 22},{-6, -5},{3, 3},{5, -5} });

}