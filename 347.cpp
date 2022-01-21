class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> freq;
        for (auto num : nums)
            freq[num]++;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (auto itr : freq)
        {
            pq.push({itr.second, itr.first});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};