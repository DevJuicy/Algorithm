#include <iostream>
#include <vector>
using namespace std;

long long MultipleElements(vector<int>& vec)
{
    long long ret = 1;
    for (int i = 0; i < vec.size(); i++)
        ret *= vec[i];
    return ret;
}

long long solution(int n)
{
    long long answer = 0;

    vector<int> elements;
    for (int i = 0; i < n; i++)
        elements.push_back(1);

    while (elements.size() > 1)
    {
        long long current = MultipleElements(elements);
        if (answer < current)
            answer = current;


        int minValue = 101;
        int minIndex = -1;
        for (int i = 0; i < elements.size() - 1; i++)
        {
            if (minValue > elements[i])
            {
                minValue = elements[i];
                minIndex = i;
            }
        }

        elements[minIndex] += 1;
        elements[elements.size() - 1] -= 1;
        if (elements[elements.size() - 1] == 0)
            elements.erase(elements.begin() + elements.size() - 1);
    }
    return answer;
}

int main()
{
    cout << solution(8);
    //cout << solution(5);
}