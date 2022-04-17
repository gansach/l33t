class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, vector<int>> ind;
        for (int i = 0; i < nums.size(); i++)
            ind[nums[i]].push_back(i);

        for (auto &itr : ind)
        {
            auto &[x, indices] = itr;
            if (target == 2 * x)
            {
                if (indices.size() >= 2)
                {
                    return {indices.front(), indices.back()};
                }
            }
            else if (ind.find(target - x) != ind.end())
            {
                return {ind[x].front(), ind[target - x].front()};
            }
        }
        return {-1, -1};
    }
};