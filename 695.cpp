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

        if (grid[i][j] == 2 || grid[i][j] == 0)
            return 0;
        grid[i][j] = 2;

        int size = 1;
        size += dfs(i + 1, j, grid);
        size += dfs(i - 1, j, grid);
        size += dfs(i, j - 1, grid);
        size += dfs(i, j + 1, grid);

        return size;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};