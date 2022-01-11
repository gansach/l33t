class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans;

        // Odd length palindrome
        for (int i = 0; i < s.size(); i++)
        {
            int j = i - 1, k = i + 1;
            while (j >= 0 && k < s.size() && s[j] == s[k])
            {
                j--, k++;
            }
            if (k - j - 1 > ans.size())
            {
                ans = string(s.begin() + j + 1, s.begin() + k);
            }
        }

        // Even length palindrome
        for (int i = 0; i < s.size(); i++)
        {
            int j = i, k = i + 1;
            while (j >= 0 && k < s.size() && s[j] == s[k])
            {
                j--, k++;
            }
            if (k - j - 1 > ans.size())
            {
                ans = string(s.begin() + j + 1, s.begin() + k);
            }
        }
        return ans;
    }
};