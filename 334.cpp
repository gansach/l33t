class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int l = INT_MAX, m = INT_MAX;

        for (auto num : nums)
        {
            if (num > m)
                return true;
            l = min(l, num);
            if (num > l)
                m = min(m, num);
        }
        return false;
    }
};