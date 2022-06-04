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

// Alternative implementation
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[i] >= nums[j])
                j++;
            else
                swap(nums[j], nums[++i]);
        }
        return i + 1;
    }
};