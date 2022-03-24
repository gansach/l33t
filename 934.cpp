// Paint islands separate colors the multi source BFS from whole island through water
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int color)
    {
        int n = grid.size();
        if (!(i >= 0 && i < n && j >= 0 && j < n))
            return;

        if (grid[i][j] == 0 || grid[i][j] == color)
            return;
        grid[i][j] = color;

        dfs(i + 1, j, grid, color);
        dfs(i - 1, j, grid, color);
        dfs(i, j - 1, grid, color);
        dfs(i, j + 1, grid, color);
    }

    void colorIsland(vector<vector<int>> &grid, int color)
    {
        int n = grid.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid, color);
                    return;
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        const int ISLAND1 = 2;
        const int ISLAND2 = 3;

        int n = grid.size();

        colorIsland(grid, ISLAND1);
        colorIsland(grid, ISLAND2);

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == ISLAND1)
                    q.push({i, j, 0});
            }
        }

        vector<pair<int, int>> directions({{0, 1}, {0, -1}, {-1, 0}, {1, 0}});

        const int VISITED = 5;
        while (!q.empty())
        {
            auto [i, j, dist] = q.front();
            q.pop();

            if (grid[i][j] == VISITED)
                continue;
            grid[i][j] = VISITED;

            for (auto &direction : directions)
            {
                auto [di, dj] = direction;
                int ii = i + di;
                int jj = j + dj;

                if ((ii >= 0 && ii < n && jj >= 0 && jj < n) && (grid[ii][jj] == 0 || grid[ii][jj] == ISLAND2))
                {
                    if (grid[ii][jj] == ISLAND2)
                        return dist;
                    q.push({ii, jj, dist + 1});
                }
            }
        }
        return -1;
    }
};