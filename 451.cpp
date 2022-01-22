class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> freq;
        for (auto c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto itr : freq)
            pq.push({itr.second, itr.first});

        string result;
        while (!pq.empty())
        {
            for (int i = 0; i < pq.top().first; i++)
                result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};