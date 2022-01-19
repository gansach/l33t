class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<long long> dp(amount + 1, LONG_LONG_MAX);
        dp[0] = 0;
        for (long long i = 0; i <= amount; i++)
        {
            if (dp[i] == LONG_LONG_MAX)
                continue;
            for (auto coin : coins)
            {
                if (i + coin <= amount)
                    dp[i + coin] = min(dp[i + coin], 1 + dp[i]);
            }
        }
        return dp.back() == LONG_LONG_MAX ? -1 : dp.back();
    }
};