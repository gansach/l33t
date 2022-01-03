class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int p = 0;

        int ans = INT_MAX;

        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {

            int p = (l + r) / 2;

            if (nums[l] <= nums[r])
            {
                ans = min(ans, nums[l]);
                break;
            }

            int next = (p + 1) % n;
            int prev = (p - 1 + n) % n;

            if (nums[p] < nums[prev] && nums[p] < nums[next])
            {
                ans = min(ans, nums[p]);
                break;
            }
            else if (nums[p] >= nums[l] && nums[p] >= nums[r])
                l = p + 1;
            else if (nums[p] <= nums[l] && nums[p] <= nums[r])
                r = p - 1;
        }

        return ans;
    }
};