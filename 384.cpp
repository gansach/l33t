class Solution
{
    vector<int> nums, original;

public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        this->original = nums;
    }

    vector<int> reset()
    {
        return nums = original;
    }

    vector<int> shuffle()
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = i + (rand() % (nums.size() - i));
            swap(nums[i], nums[idx]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */