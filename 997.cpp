class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> indegree(n, 0), outdegree(n, 0);

        for (auto &t : trust)
        {
            int a = t[0], b = t[1];

            outdegree[a - 1]++;
            indegree[b - 1]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i + 1;
        }
        return -1;
    }
};