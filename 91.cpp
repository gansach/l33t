/*
class Solution
{
public:
    int decodings(int i, string &s, vector<int> &memo)
    {
        if (i == s.size())
            return 1;

        if (memo[i] != -1)
            return memo[i];

        int one = 0;
        if (s[i] != '0')
            one = decodings(i + 1, s, memo);

        int two = 0;
        if (i + 1 < s.size() && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')))
            two = decodings(i + 2, s, memo);

        return memo[i] = one + two;
    }

    int numDecodings(string s)
    {
        vector<int> memo(s.size(), -1);
        return decodings(0, s, memo);
    }
};
*/