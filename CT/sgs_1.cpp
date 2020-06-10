#include <iostream>
#include <vector>

using namespace std;

int C, P;
vector<int> N;
vector<int> card;

void Shuffle(int n)
{

    vector<int> tempCard = card;

    while (tempCard.size() > n * 2)
    {
        int index = 0;
        vector<int> preCard;
        vector<int> postCard;
        for (; index < n; index++)
        {
            postCard.push_back(tempCard[index]);
        }

        for (; index < tempCard.size() - n; index++)
        {
            preCard.push_back(tempCard[index]);
        }

        for (; index < tempCard.size(); index++)
        {
            postCard.push_back(tempCard[index]);
        }

        for (int i = 0; i < preCard.size(); i++)
        {
            card[i] = preCard[i];
        }

        for (int i = 0; i < postCard.size(); i++)
        {
            card[tempCard.size() - (n * 2) + i] = postCard[i];
        }

        tempCard = preCard;
    }
}

void Input()
{
    cin >> C >> P;

    for (int i = 0; i < P; i++)
    {
        int temp;
        cin >> temp;
        N.push_back(temp);
    }

    for (int i = 0; i < C; i++)
    {
        card.push_back(i + 1);
    }
}

void Solution()
{
    for (int i = 0; i < N.size(); i++)
    {
        Shuffle(N[i]);
    }
}

int main()
{
    Input();
    Solution();

    for (int i = 0; i < 5; i++)
        cout << card[i] << " ";
}