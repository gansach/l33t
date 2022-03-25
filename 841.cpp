// DFS to get size of island, one island of size n should exist
class Solution
{
public:
    int dfs(int room, vector<vector<int>> &rooms, vector<bool> &visited)
    {
        if (visited[room])
            return 0;
        visited[room] = true;

        int size = 1;
        for (auto neighbor : rooms[room])
            size += dfs(neighbor, rooms, visited);
        return size;
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();

        vector<bool> visited(n, false);
        return dfs(0, rooms, visited) == n;
    }
};

// DFS to visit rooms and check of unvisited rooms
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