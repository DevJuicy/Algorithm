class NT_1
{
    public int solution(int[] arr)
    {
        int answer = 0;

        for (int i = 0; i < arr.Length; i++)
        {
            if (FindTeam(arr, i))
                answer++;
        }
        return answer / 3;
    }

    bool FindTeam(int[] arr, int index)
    {
        return index + 1 == arr[arr[arr[index] - 1] - 1];
    }

}
