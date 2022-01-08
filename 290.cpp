class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {

        vector<string> strs;
        stringstream ss(str);
        while (ss.good())
        {
            string t;
            ss >> t;
            strs.push_back(t);
        }

        if (pattern.size() != strs.size())
            return false;

        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            string s = strs[i];

            if (c2s.find(c) == c2s.end())
                c2s[c] = s;
            else if (c2s[c] != s)
                return false;

            if (s2c.find(s) == s2c.end())
                s2c[s] = c;
            else if (s2c[s] != c)
                return false;
        }

        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            string s = strs[i];

            if (c2s[c] != s || s2c[s] != c)
                return false;
        }
        return true;
    }
};