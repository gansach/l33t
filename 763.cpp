class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};

/* Intervals merge
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, pair<int, int>> mp;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (mp.find(c) == mp.end())
                mp[c] = {i, i};
            else
                mp[c].second = i;
        }

        vector<pair<int, int>> intervals;
        for (auto &itr : mp)
            intervals.push_back(itr.second);

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            auto [s, e] = intervals[i];
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j].first > e)
                    break;
                e = max(e, intervals[j].second);
                i = j;
            }
            merged.push_back({s, e});
        }

        vector<int> ans;
        for (auto &itr : merged)
            ans.push_back(itr.second - itr.first + 1);
        return ans;
    }
};
*/