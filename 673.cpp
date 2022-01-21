class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        vector<pair<int, int>> dp;

        for (int i = 0; i < nums.size(); i++)
        {
            int lcsSize = 1;
            int lcsCount = 1;

            for (int j = 0; j < i; j++)
            {
                auto [size, cnt] = dp[j];

                if (nums[j] < nums[i])
                {
                    if (size + 1 > lcsSize)
                    {
                        lcsSize = size + 1;
                        lcsCount = cnt;
                    }
                    else if (size + 1 == lcsSize)
                        lcsCount += cnt;
                }
            }
            dp.push_back({lcsSize, lcsCount});
        }

        int lcsSize = 0;
        int lcsCount = 0;

        for (auto &itr : dp)
        {
            auto [size, cnt] = itr;
            if (size > lcsSize)
            {
                lcsSize = size;
                lcsCount = cnt;
            }
            else if (lcsSize == size)
                lcsCount += cnt;
        }

        return lcsCount;
    }
};