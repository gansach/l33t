class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> freq;
        for (auto c : s)
            freq[c]++;

        int odd = 0;

        int ans = 0;
        for (auto itr : freq)
        {
            auto [k, v] = itr;

            if (v % 2 == 1)
                odd = 1;
            ans += v / 2;
        }
        return (ans * 2) + odd;
    }
};