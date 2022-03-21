// Greedy
class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {

        long long ans = ((long long)k * (k + 1)) / 2;

        for (auto itr : set<int>(nums.begin(), nums.end()))
        {
            if (itr <= k)
            {
                ans -= itr;
                ans += ++k;
            }
            else
                break;
        }

        return ans;
    }
};

// Gaps between continuous number ranges
class Solution
{
public:
    long long rangeSum(long long start, long long end)
    {
        long long endSum = (end * (end + 1)) / 2;
        long long startSum = ((start - 1) * start) / 2;
        return endSum - startSum;
    }
    long long minimalKSum(vector<int> &numbers, int k)
    {
        set<int> unique(numbers.begin(), numbers.end());

        vector<int> nums;
        for (auto itr : unique)
            nums.push_back(itr);

        vector<pair<int, int>> ranges;

        int start = nums.front();
        int end = nums.front();

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                end = nums[i];
            }
            else
            {
                ranges.push_back({start, end});
                start = nums[i];
                end = nums[i];
            }
        }
        ranges.push_back({start, end});

        vector<pair<int, int>> free_ranges;
        if (ranges.front().first != 1)
            free_ranges.push_back({1, ranges.front().first - 1});

        for (int i = 1; i < ranges.size(); i++)
        {
            free_ranges.push_back({ranges[i - 1].second + 1, ranges[i].first - 1});
        }
        free_ranges.push_back({ranges.back().second + 1, INT_MAX});

        long long ans = 0;
        for (auto itr : free_ranges)
        {
            if (k == 0)
                return ans;
            auto [start, end] = itr;
            int cnt = end - start + 1;

            if (cnt <= k)
            {
                ans += rangeSum(start, end);
                cout << "\nhere1 " << start << " " << end << endl;
                k -= cnt;
            }
            else
            {
                cout << "\nhere2 " << start << " " << end << endl;
                ans += rangeSum(start, start + k - 1);
                return ans;
            }
        }
        return 0;
    }
};