class Solution
{
public:
    void getSubsets(int i, vector<int> &nums, vector<int> &subset, set<vector<int>> &subsetsArr)
    {
        if (i == nums.size())
        {
            vector<int> tmp(subset.begin(), subset.end());
            sort(tmp.begin(), tmp.end());
            subsetsArr.insert(tmp);
            return;
        }

        subset.push_back(nums[i]);
        getSubsets(i + 1, nums, subset, subsetsArr);
        subset.pop_back();

        getSubsets(i + 1, nums, subset, subsetsArr);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector<int>> subsetsArr;
        vector<int> subset;

        getSubsets(0, nums, subset, subsetsArr);

        return vector<vector<int>>(subsetsArr.begin(), subsetsArr.end());
    }
};