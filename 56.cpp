class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); i++)
        {
            int s = intervals[i][0], e = intervals[i][1];

            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j][0] > e)
                    break;
                e = max(e, intervals[j][1]);
                i = j;
            }
            merged.push_back({s, e});
        }
        return merged;
    }
};