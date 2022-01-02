class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 1;
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (cnt == 0)
                ans = nums[i];

            if (nums[i] == ans)
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};