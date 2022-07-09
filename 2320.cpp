class Solution
{
public:
    int countHousePlacements(int n)
    {
        int M = 1000000000 + 7;

        long long a = 0, b = 1;
        for (int i = 0; i < n + 1; i++)
        {
            int tmp = (a % M + b % M) % M;
            a = b;
            b = tmp;
        }
        return ((b % M) * (b % M)) % M;
    }
};