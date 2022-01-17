class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> LIS({nums.front()});

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > LIS.back())
                LIS.push_back(nums[i]);
            else
            {
                int idx = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
                LIS[idx] = nums[i];
            }
        }
        return LIS.size();
    }
};
/* O(n^2)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            int lis = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    lis = max(lis, dp[j] + 1);
            }
            dp[i] = lis;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
/*