class Solution
{
public:
    int bSearch(vector<int> &nums, int l, int r, int key)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < key)
                l = mid + 1;
            else if (nums[mid] > key)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }
    int pivot(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            if (nums[l] <= nums[r])
                return l;
            int mid = (l + r) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return mid;
            else if (nums[mid] < nums[l])
                r = mid - 1;
            else if (nums[mid] > nums[r])
                l = mid + 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int p = pivot(nums);
        int i1 = bSearch(nums, 0, p - 1, target);
        int i2 = bSearch(nums, p, nums.size() - 1, target);

        if (i1 != -1)
            return i1;
        if (i2 != -1)
            return i2;
        return -1;
    }
};