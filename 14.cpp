class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string lcp;
        int n = INT_MAX;
        for (auto &str : strs)
            n = min(n, (int)str.size());

        for (int i = 0; i < n; i++)
        {
            char c = strs.front()[i];

            for (auto &str : strs)
            {
                if (str[i] != c)
                {
                    return lcp;
                }
            }
            lcp.push_back(c);
        }
        return lcp;
    }
};