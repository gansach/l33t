class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
            return vector<int>();

        vector<int> freq(26, 0), window(26, 0);
        for (int i = 0; i < p.size(); i++)
        {
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        vector<int> startIndices;
        if (freq == window)
            startIndices.push_back(0);

        int i = 0, j = p.size() - 1;
        while (j < s.size() - 1)
        {
            window[s[i] - 'a']--;
            i++;

            j++;
            window[s[j] - 'a']++;

            if (window == freq)
                startIndices.push_back(i);
        }
        return startIndices;
    }
};