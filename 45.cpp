class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        int max_reach = nums[0];
        int reach = nums[0];

        int jumps = 1;

        for (int i = 1; i <= min(n, max_reach); i++)
        {
            reach = max(reach, i + nums[i]);

            if (i == n - 1)
                return jumps;

            if (i == max_reach)
            {
                max_reach = reach;
                jumps++;
            }
        }
        return 0;
    }
};
/*
class Solution {
public:
    int steps(int i, vector<int>& nums, vector<int>& memo) {
        if(i >= nums.size() - 1) return 0;

        if (memo[i] != -1) return memo[i];

        int min_steps = nums.size();
        for(int j = 1; j <= nums[i]; j++) {
            min_steps = min(min_steps, 1 + steps(i + j, nums, memo));
        }
        return memo[i] = min_steps;
    }

    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return steps(0, nums, memo);
    }
};
*/