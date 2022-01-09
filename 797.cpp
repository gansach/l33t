class Solution
{
public:
    vector<vector<int>> paths;

    void dfs(int src, int dest, vector<vector<int>> &graph, vector<int> &path, vector<bool> &visited)
    {
        if (src == dest)
        {
            path.push_back(dest);
            paths.push_back(path);
            path.pop_back();
            return;
        }

        if (visited[src])
            return;
        visited[src] = true;

        path.push_back(src);
        for (auto neighbor : graph[src])
        {
            dfs(neighbor, dest, graph, path, visited);
        }

        visited[src] = false;
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        paths.clear();

        int n = graph.size();

        vector<bool> visited(n, false);

        vector<int> path;
        dfs(0, n - 1, graph, path, visited);

        return paths;
    }
};