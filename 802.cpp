// White Gray Black DFS
// 1. Mark node as GRAY
// 2. If any neighbor is GRAY cycle is present
// 3. If neighbor is WHITE check for cycle starting from neighbor
// 4. Since all neighbors are processed, mark current node as BLACK

class Solution
{
public:
    enum state
    {
        WHITE,
        GRAY,
        BLACK
    };

    bool hasCycle(int node, vector<vector<int>> &adj, vector<int> &color)
    {

        color[node] = GRAY;

        for (auto neighbor : adj[node])
        {
            if (color[neighbor] == GRAY)
                return true;

            if (color[neighbor] == WHITE && hasCycle(neighbor, adj, color))
                return true;
        }

        color[node] = BLACK;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, WHITE);

        vector<int> safeNodes;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == WHITE)
                hasCycle(i, graph, color);

            if (color[i] == BLACK)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};