class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        int i = 0, j = 1;
        while (i < nums.size())
        {
            while (j < nums.size() && nums[i] == nums[j])
                j++;
            swap(nums[k++], nums[i]);
            i = j;
        }
        return k;
    }
};