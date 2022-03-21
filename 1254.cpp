class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.front().size();

        if (!isSafe(i, j, n, m))
            return false;
        if (grid[i][j] == 1)
            return false;

        grid[i][j] = 1;

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);

        return true;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.front().size();

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0)
                dfs(i, 0, grid);
            if (grid[i][m - 1] == 0)
                dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 0)
                dfs(0, j, grid);
            if (grid[n - 1][j] == 0)
                dfs(n - 1, j, grid);
        }

        int numClosedIslands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    numClosedIslands += dfs(i, j, grid);
            }
        }
        return numClosedIslands;
    }
};