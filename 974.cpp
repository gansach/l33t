class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> remainderFreq(k, 0);
        remainderFreq[0] = 1;

        int rem = 0, subarrays = 0;
        for (auto num : nums)
        {
            rem = (rem + num) % k;
            if (rem < 0)
                rem += k;
            subarrays += remainderFreq[rem];
            remainderFreq[rem]++;
        }
        return subarrays;
    }
};