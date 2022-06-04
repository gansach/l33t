class Solution
{
public:
    bool digitCount(string num)
    {
        map<char, int> freq;
        for (auto c : num)
            freq[c]++;

        for (int i = 0; i < num.size(); i++)
        {
            if (freq[i + '0'] != (num[i] - '0'))
                return false;
        }
        return true;
    }
};