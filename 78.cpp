class Solution
{
public:
    void getSubsets(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsetsArr)
    {
        if (i == nums.size())
        {
            subsetsArr.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        getSubsets(i + 1, nums, subset, subsetsArr);
        subset.pop_back();

        getSubsets(i + 1, nums, subset, subsetsArr);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subsetsArr;
        vector<int> subset;

        getSubsets(0, nums, subset, subsetsArr);

        return subsetsArr;
    }
};