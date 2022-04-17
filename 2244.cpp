class Solution
{
public:
    map<int, int> memo;
    int minRounds(int n)
    {
        if (memo[n])
            return memo[n];
        if (n == 0)
            return 0;
        else if (n == 2)
            return 1;
        else if (n > 2)
            return memo[n] = 1 + min(minRounds(n - 2), minRounds(n - 3));
        return INT_MAX;
    }

    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> freq;
        for (auto task : tasks)
            freq[task]++;
        int ans = 0;
        for (auto itr : freq)
        {
            auto [k, v] = itr;
            int x = minRounds(v);
            if (x == INT_MAX)
                return -1;
            ans += x;
        }
        return ans;
    }
};