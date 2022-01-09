class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> freq(26);
            for (auto c : strs[i])
                freq[c - 'a']++;
            mp[freq].push_back(i);
        }

        vector<vector<string>> groups;
        for (auto &itr : mp)
        {
            vector<string> group;
            for (auto i : itr.second)
                group.push_back(strs[i]);
            groups.push_back(group);
        }
        return groups;
    }
};