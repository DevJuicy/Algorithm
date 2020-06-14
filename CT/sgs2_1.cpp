#include <iostream>
#include <vector>

using namespace std;

string address;
vector<string> addressVector;

void Input()
{
    cin >> address;
}

char ParseToHex(string binary)
{
    int decimal = 0;
    decimal += (binary[0]-'0') * 8;
    decimal += (binary[1]-'0') * 4;
    decimal += (binary[2]-'0') * 2;
    decimal += (binary[3]-'0') * 1;

    if (decimal < 10)
        return decimal + '0';
    else if (decimal == 10)
        return 'a';
    else if (decimal == 11)
        return 'b';
    else if (decimal == 12)
        return 'c';
    else if (decimal == 13)
        return 'd';
    else if (decimal == 14)
        return 'e';
    else if (decimal == 15)
        return 'f';
    return '0';
}

string Solution()
{
    string answer = "";
    for (int i = 0; i < 32; i++)
    {
        string current;
        current += address[i*4];
        current += address[i*4+1];
        current += address[i*4+2];
        current += address[i*4+3];
        addressVector.push_back(current);
    }

    for (int i = 0; i < 32; i++)
    {
        answer += ParseToHex(addressVector[i]);

        if (i % 4 == 3 && i < 31)
            answer += ':';
    }

    return answer;
}

int main()
{
    Input();
    cout << Solution();
}

