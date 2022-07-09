class Solution
{
public:
    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void join(int i, int j, vector<int> &parent, vector<int> &rank)
    {
        i = find(i, parent);
        j = find(j, parent);

        if (rank[j] <= rank[i])
        {
            parent[j] = i;
            rank[i] += rank[j];
        }
        else
        {
            parent[i] = j;
            rank[j] += rank[i];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> parent(edges.size(), -1), rank(edges.size(), 1);

        for (int i = 0; i < edges.size(); i++)
            parent[i] = i;

        for (auto &edge : edges)
        {
            int s = edge.front(), d = edge.back();
            if (find(s - 1, parent) == find(d - 1, parent))
                return {s, d};
            join(s - 1, d - 1, parent, rank);
        }
        return {-1, -1};
    }
};