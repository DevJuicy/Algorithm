#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int C, P;

vector<int> exceptionCount;
vector<int> card;

void Shuffle(int N)
{
    vector<int> currentCard = card;
    vector<int> preCard;
    stack<int> postCard;

    while (currentCard.size() > N*2)
    {
        for (int i = currentCard.size() -1 ; i >= currentCard.size() - N; i--)
        {
            postCard.push(currentCard[i]);
        }
        for (int i = N; i < currentCard.size() - N; i++)
        {
            preCard.push_back(currentCard[i]);
        }
        for (int i = N - 1; i >= 0; i--)
        {
            postCard.push(currentCard[i]);
        }
        currentCard = preCard;
        preCard.clear();
    }
    card = currentCard;
    while (!postCard.empty())
    {
        card.push_back(postCard.top());
        postCard.pop();
    }
}

void Input()
{
    cin >> C >> P;
    for (int i = 0; i < C; i++)
    {
        card.push_back(i + 1);
    }

    for (int i = 0; i < P; i++)
    {
        int temp;
        cin >> temp;
        exceptionCount.push_back(temp);
    }
}

void Solution()
{
    for (int i = 0; i < P; i++)
    {
        Shuffle(exceptionCount[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << card[i] << endl;
    }
}

int main()
{
    Input();
    Solution();
}