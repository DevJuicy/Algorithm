#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool IsStar(char c)
{
	return '*' == c;
}

bool IsSharp(char c)
{
	return '#' == c;
}

int solution(string dartResult)
{
	int score[3];
	int currentScore = 0;
	int scoreIndex = 0;

	for (int i = 0; i < dartResult.size(); i++)
	{
		// 숫자부분
		if (dartResult[i] == '1' && dartResult[i + 1] == '0') // 10인경우
		{
			currentScore = 10;
			i++;
		}
		else
			currentScore = dartResult[i] - '0';
		i++;

		// 곱부분
		if (dartResult[i] == 'D')
			currentScore *= currentScore;
		else if (dartResult[i] == 'T')
			currentScore = currentScore * currentScore * currentScore;
		i++;

		// 보너스 부분
		if (IsStar(dartResult[i]))
		{
			score[scoreIndex] = currentScore;
			if (scoreIndex == 0)
				score[0] *= 2;
			else if (scoreIndex == 1)
			{
				score[0] *= 2;
				score[1] *= 2;
			}
			else if (scoreIndex == 2)
			{
				score[1] *= 2;
				score[2] *= 2;
			}
		}
		else if (IsSharp(dartResult[i]))
		{
			score[scoreIndex] = currentScore * -1;
		}
		else
		{
			score[scoreIndex] = currentScore;
			i--;
		}
		scoreIndex++;
	}
	return score[0] + score[1] + score[2];
}

int main(void)
{
	cout << "answer : " << solution("1S2D*3T") << endl;
	cout << "answer : " << solution("1D2S#10S") << endl;
	cout << "answer : " << solution("1D2S0T") << endl;
	cout << "answer : " << solution("1S*2T*3S") << endl;
	cout << "answer : " << solution("1D#2S*3S") << endl;
	cout << "answer : " << solution("1T2D3D#") << endl;
	cout << "answer : " << solution("1D2S3T*") << endl;
}