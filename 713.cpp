class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int p = 1;
        int ans = 0;
        int start = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            p *= nums[end];
            while (p >= k)
                p /= nums[start++];
            ans += end - start + 1;
        }
        return ans;
    }
};