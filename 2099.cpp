class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < nums.size(); i++)
            numIndex.push_back({nums[i], i});

        sort(numIndex.begin(), numIndex.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });

        vector<pair<int, int>> ans(numIndex.begin(), numIndex.begin() + k);
        sort(ans.begin(), ans.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        vector<int> result;
        for (auto &itr : ans)
            result.push_back(itr.first);
        return result;
    }
};