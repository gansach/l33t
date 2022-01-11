class Solution
{
public:
    void getCombinations(int i, vector<int> &candidates, vector<int> &combination, vector<vector<int>> &combinations, int target)
    {
        if (target == 0)
        {
            combinations.push_back(combination);
            return;
        }
        else if (i == candidates.size() || target < 0)
            return;

        if (candidates[i] <= target)
        {

            combination.push_back(candidates[i]);
            getCombinations(i, candidates, combination, combinations, target - candidates[i]);
            combination.pop_back();

            getCombinations(i + 1, candidates, combination, combinations, target);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> combinations;
        vector<int> combination;
        getCombinations(0, candidates, combination, combinations, target);
        return combinations;
    }
};