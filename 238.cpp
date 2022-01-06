class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
            ans[i] = ans[i - 1] * nums[i - 1];

        int p = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            p = nums[i + 1] * p;
            ans[i] *= p;
        }
        return ans;
    }
};
/*
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        vector<int> l(nums.size() + 1, 1);
        for (int i = 1; i < l.size(); i++)
            l[i] = l[i - 1] * nums[i - 1];

        vector<int> r(nums.size() + 1, 1);
        for (int i = nums.size() - 1; i >= 0; i--)
            r[i] = r[i + 1] * nums[i];

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            ans.push_back(l[i] * r[i + 1]);

        return ans;
    }
};
*/