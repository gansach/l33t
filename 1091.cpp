class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] == 1)
            return -1;

        using tiii = tuple<int, int, int>;

        vector<pair<int, int>> directions({{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}});

        queue<tiii> q({{0, 0, 1}});
        grid[0][0] = 1;

        while (!q.empty())
        {
            auto [i, j, dist] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1)
                return dist;

            for (auto d : directions)
            {
                auto [dx, dy] = d;
                int ii = i + dx;
                int jj = j + dy;

                if ((ii >= 0 && jj >= 0 && ii < n && jj < n) && grid[ii][jj] == 0)
                {
                    q.push({ii, jj, dist + 1});
                    grid[ii][jj] = 1;
                }
            }
        }
        return -1;
    }
};