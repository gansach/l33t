class Solution
{
public:
    void next_permutation(vector<int> &v)
    {
        std::next_permutation(v.begin(), v.end());
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> permutations;
        int f = 1;
        for (int i = 1; i <= nums.size(); i++)
            f *= i;

        for (int i = 0; i < f; i++)
        {
            permutations.insert(nums);
            next_permutation(nums);
        }
        return vector<vector<int>>(permutations.begin(), permutations.end());
    }
};