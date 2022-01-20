class Solution
{
public:
    void explore(int node, map<int, vector<int>> &adj, vector<int> &visited)
    {
        if (visited[node])
            return;
        visited[node] = true;

        for (auto neighbor : adj[node])
        {
            explore(neighbor, adj, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        map<int, vector<int>> adj;
        for (int i = 0; i < rooms.size(); i++)
        {
            for (auto room : rooms[i])
            {
                adj[i].push_back(room);
            }
        }

        vector<int> visited(rooms.size(), false);
        explore(0, adj, visited);

        for (auto itr : visited)
            if (itr == false)
                return false;

        return true;
    }
};