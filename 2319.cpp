class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid.front().size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j || j == (n - 1 - i))
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else if (grid[i][j] != 0)
                    return false;
            }
        }
        return true;
    }
};