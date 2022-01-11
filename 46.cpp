class Solution
{
public:
    void next_permutation(vector<int> &v)
    {
        int index1 = v.size() - 1;
        for (int i = index1 - 1; i >= 0; i--)
        {
            if (v[i] < v[i + 1])
            {
                index1 = i;
                break;
            }
        }

        int index2 = v.size() - 1;
        for (int j = v.size() - 1; j > index1; j--)
        {
            if (v[j] > v[index1])
            {
                index2 = j;
                break;
            }
        }

        swap(v[index1], v[index2]);
        if (index1 == v.size() - 1 && index2 == v.size() - 1)
            index1 = -1;
        reverse(v.begin() + index1 + 1, v.end());
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        int f = 1;
        for (int i = 1; i <= nums.size(); i++)
            f *= i;

        for (int i = 0; i < f; i++)
        {
            ans.push_back(nums);
            next_permutation(nums);
        }

        return ans;
    }
};