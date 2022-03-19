class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto num : nums)
            freq[num]++;
        for (auto itr : freq)
        {
            if (itr.second % 2 == 1)
                return false;
        }
        return true;
    }
};