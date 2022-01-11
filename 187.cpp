class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() <= 10)
            return vector<string>();

        unordered_set<string> freq1, freqMore;

        for (int i = 0; i <= s.size() - 10; i++)
        {
            string t(s.begin() + i, s.begin() + i + 10);
            if (freq1.find(t) != freq1.end())
                freqMore.insert(t);
            else
                freq1.insert(t);
        }
        return vector<string>(freqMore.begin(), freqMore.end());
    }
};