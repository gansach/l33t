class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited)
    {
        int n = heights.size();
        int m = heights.front().size();

        queue<tuple<int, int, int>> q({{i, j, heights[i][j]}});

        vector<pair<int, int>> directions({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

        while (!q.empty())
        {

            auto [i, j, height] = q.front();
            q.pop();

            if (visited[i][j])
                continue;
            visited[i][j] = true;

            for (auto &direction : directions)
            {
                auto [di, dj] = direction;

                int ii = i + di;
                int jj = j + dj;

                if ((ii >= 0 && ii < n && jj >= 0 && jj < m) && heights[ii][jj] >= height)
                {
                    q.push({ii, jj, heights[ii][jj]});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights.front().size();

        set<vector<int>> pacific, atlantic;

        for (int i = 0; i < n; i++)
        {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            bfs(i, 0, heights, visited);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (visited[i][j])
                        pacific.insert({i, j});
        }

        for (int j = 0; j < m; j++)
        {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            bfs(0, j, heights, visited);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (visited[i][j])
                        pacific.insert({i, j});
        }

        for (int i = 0; i < n; i++)
        {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            bfs(i, m - 1, heights, visited);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (visited[i][j])
                        atlantic.insert({i, j});
        }

        for (int j = 0; j < m; j++)
        {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            bfs(n - 1, j, heights, visited);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (visited[i][j])
                        atlantic.insert({i, j});
        }

        vector<vector<int>> ans;
        for (auto &itr : pacific)
            if (atlantic.find(itr) != atlantic.end())
                ans.push_back(itr);
        return ans;
    }
};