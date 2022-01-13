class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums.front();

        return max(robDP(0, nums.size() - 1, nums), robDP(1, nums.size(), nums));
    }

    int robDP(int l, int r, vector<int> &nums)
    {
        int rob_prev = 0;
        int rob_curr = 0;
        for (int i = l; i < r; i++)
        {
            int rob_prev_prev = rob_prev;
            rob_prev = rob_curr;
            rob_curr = max(nums[i] + rob_prev_prev, rob_prev);
        }
        return rob_curr;
    }
};

/*
class Solution
{
public:
    int robRecurse(int i, int n, vector<int> &nums, vector<int> &memo)
    {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int r = nums[i] + robRecurse(i + 2, n, nums, memo);
        int dr = robRecurse(i + 1, n, nums, memo);

        return memo[i] = max(r, dr);
    }

    int rob(vector<int> &nums)
    {
        vector<int> memo;

        memo = vector<int>(nums.size(), -1);
        int robFirst = nums[0] + robRecurse(2, nums.size() - 1, nums, memo);

        memo = vector<int>(nums.size(), -1);
        int dontRobFirst = robRecurse(1, nums.size(), nums, memo);

        return max({robFirst, dontRobFirst});
    }
};
*/