class Solution
{
public:
    int bSearch(vector<int> &nums, int target, bool starting)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                if (starting)
                {
                    if (mid == 0 || nums[mid - 1] != target)
                        return mid;
                    r = mid - 1;
                }
                else
                {
                    if (mid == nums.size() - 1 || nums[mid + 1] != target)
                        return mid;
                    l = mid + 1;
                }
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {
            bSearch(nums, target, true),
            bSearch(nums, target, false)};
    }
};