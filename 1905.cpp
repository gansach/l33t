class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(int i, int j, vector<vector<int>> &grid2, vector<vector<int>> &grid1, bool &isSubIsland)
    {
        int n = grid2.size();
        int m = grid2.front().size();

        if (!isSafe(i, j, n, m))
            return;

        if (grid2[i][j] == 0)
            return;
        grid2[i][j] = 0;

        if (grid1[i][j] != 1)
            isSubIsland = false;

        dfs(i - 1, j, grid2, grid1, isSubIsland);
        dfs(i + 1, j, grid2, grid1, isSubIsland);
        dfs(i, j - 1, grid2, grid1, isSubIsland);
        dfs(i, j + 1, grid2, grid1, isSubIsland);
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int n = grid2.size();
        int m = grid2.front().size();

        int numSubIslands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] == 1)
                {
                    bool isSubIsland = true;
                    dfs(i, j, grid2, grid1, isSubIsland);
                    if (isSubIsland)
                        numSubIslands++;
                }
            }
        }
        return numSubIslands;
    }
};