class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.front().size();

        if (!isSafe(i, j, n, m))
            return 0;
        if (grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;

        int size = 1;
        size += dfs(i - 1, j, grid);
        size += dfs(i + 1, j, grid);
        size += dfs(i, j - 1, grid);
        size += dfs(i, j + 1, grid);
        return size;
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.front().size();

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid);
            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid);
        }

        int numEnclaves = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    numEnclaves += dfs(i, j, grid);
            }
        }
        return numEnclaves;
    }
};