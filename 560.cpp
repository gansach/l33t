class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sum2freq({{0, 1}});

        int ans = 0, sum = 0;
        for (auto num : nums)
        {
            sum += num;
            ans += sum2freq[sum - k];
            sum2freq[sum]++;
        }
        return ans;
    }
};
/* TLE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> l(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            l[i] = l[i - 1] + nums[i - 1];
        }

        int ans = 0;
        for(int i = 0; i <= nums.size(); i++)
            for(int j = i + 1; j <= nums.size(); j++)
                if (l[j] - l[i] == k) ans++;
        return ans;
    }
};
*/