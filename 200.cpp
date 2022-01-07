class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    bool dfs(int i, int j, vector<vector<char>> &grid)
    {

        int n = grid.size();
        int m = grid.front().size();

        if (grid[i][j] == '0')
            return false;
        grid[i][j] = '0';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++)
        {
            int ii = i + dx[d];
            int jj = j + dy[d];

            if (isSafe(ii, jj, n, m))
                dfs(ii, jj, grid);
        }
        return true;
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size();
        int m = grid.front().size();

        int islands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && dfs(i, j, grid))
                    islands++;
            }
        }
        return islands;
    }
};