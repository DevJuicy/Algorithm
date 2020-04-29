#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<long long, long long> m;

long long getNextEmptyRoom(long long num)
{
    if (m[num] == 0)
        return num;
    return m[num] = getNextEmptyRoom(m[num]);
}


vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;

    for (auto num : room_number)
    {
        long long emptyRoom = getNextEmptyRoom(num);
        answer.push_back(emptyRoom);
        m[emptyRoom] = emptyRoom + 1;
    }

    return answer;
}

int main()
{
	solution(10, { 1,3,4,1,3,1 });
}