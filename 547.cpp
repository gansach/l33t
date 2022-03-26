// Union Find
class Solution
{
public:
    int find(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void join(int i, int j, vector<int> &parent, vector<int> &rank)
    {
        i = find(i, parent);
        j = find(j, parent);

        if (i != j)
        {
            if (rank[i] <= rank[j])
            {
                parent[i] = j;
                rank[j] += rank[i];
            }
            else
            {
                parent[j] = i;
                rank[i] += rank[j];
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n), rank(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                    join(i, j, parent, rank);
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                provinces++;
        return provinces;
    }
};

// DFS
class Solution
{
public:
    bool dfs(int i, map<int, vector<int>> &adj, vector<bool> &visited)
    {

        if (visited[i])
            return false;
        visited[i] = true;

        for (auto j : adj[i])
        {
            dfs(j, adj, visited);
        }

        return true;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();

        map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dfs(i, adj, visited))
                ans++;
        }
        return ans;
    }
};