// Undirected Cycles = edges - ((nodes - 1) - (islands - 1))

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

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> parent(n), rank(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &connection : connections)
        {
            int s = connection[0], d = connection[1];
            join(s, d, parent, rank);
        }

        int islands = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                islands++;

        int cycles = connections.size() - ((n - 1) - (islands - 1));

        if (cycles >= islands - 1)
            return islands - 1;
        return -1;
    }
};

// DFS
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        if (visited[node])
            return;
        visited[node] = true;

        for (auto &neighbor : adj[node])
            dfs(neighbor, adj, visited);
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n, vector<int>());
        for (auto &connection : connections)
        {
            int s = connection[0], d = connection[1];
            adj[s].push_back(d);
            adj[d].push_back(s);
        }

        int islands = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                islands++;
            }
        }

        int cycles = connections.size() - n + islands;
        if (cycles >= islands - 1)
            return islands - 1;
        return -1;
    }
};