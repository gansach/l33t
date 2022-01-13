class Solution
{
public:
    int robRecursive(int i, vector<int> &nums, vector<int> &memo)
    {
        if (i >= nums.size())
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int r = nums[i] + robRecursive(i + 2, nums, memo);
        int dr = robRecursive(i + 1, nums, memo);

        return memo[i] = max(r, dr);
    }

    int robDP(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp.back();
    }

    int rob(vector<int> &nums)
    {
        int rob_prev = 0;
        int rob_curr = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int rob_prev_prev = rob_prev;
            rob_prev = rob_curr;
            rob_curr = max(nums[i] + rob_prev_prev, rob_prev);
        }
        return rob_curr;
    }
};