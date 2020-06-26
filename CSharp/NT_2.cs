using System;
using System.Collections.Generic;
class NT_2
{
    public int solution(int k, int[] score)
    {
        bool[] rightScore = new bool[score.Length];
        int[] scoreGap = new int[score.Length];
        Dictionary<int, int> gaps = new Dictionary<int, int>();

        for (int i = 0; i < score.Length; i++)
            rightScore[i] = true;

        for (int i = 1; i < score.Length; i++)
        {
            scoreGap[i] = Math.Abs(score[i] - score[i - 1]);

            if (!gaps.ContainsKey(scoreGap[i]))
                gaps[scoreGap[i]] = 1;
            else
                gaps[scoreGap[i]]++;
        }

        for (int i = 1; i < scoreGap.Length; i++)
        {
            if (gaps[scoreGap[i]] >= k)
            {
                rightScore[i] = false;
                rightScore[i - 1] = false;
            }
        }

        int rightCount = 0;
        foreach(var element in rightScore)
        {
            if (element)
                rightCount++;
        }

        return rightCount;
    }
}
