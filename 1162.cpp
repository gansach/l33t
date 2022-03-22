// Multi source BFS
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();

        queue<tuple<int, int, int>> q;

        vector<vector<int>> dist(n, vector<int>(n, -1));

        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j, 0});
                    cnt1++;
                }
            }
        }

        if (cnt1 == n * n || cnt1 == 0)
            return -1;

        vector<pair<int, int>> directions({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        while (!q.empty())
        {
            auto [i, j, d] = q.front();
            q.pop();

            if (dist[i][j] == -1)
            {
                dist[i][j] = d;

                for (auto &direction : directions)
                {
                    auto [di, dj] = direction;

                    int ii = i + di;
                    int jj = j + dj;

                    if (ii >= 0 && ii < n && jj >= 0 && jj < n)
                    {
                        q.push({ii, jj, d + 1});
                    }
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dist[i][j]);
        return ans;
    }
};