class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int> freq;
        for (int i = 0; i < messages.size(); i++)
        {
            freq[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
        }
        int max_words = INT_MIN;
        for (auto &itr : freq)
            max_words = max(max_words, itr.second);

        vector<string> conts;
        for (auto &itr : freq)
            if (itr.second == max_words)
                conts.push_back(itr.first);
        sort(conts.begin(), conts.end());

        return conts.back();
    }
};