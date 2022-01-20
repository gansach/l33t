class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> indegree(n, 0);

        for (auto &edge : edges)
        {
            int s = edge[0], d = edge[1];
            indegree[d]++;
        }

        vector<int> indegreeZero;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                indegreeZero.push_back(i);
        }
        return indegreeZero;
    }
};