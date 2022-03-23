// Multi source BFS
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat.front().size();

        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                    q.push({i, j, 0});
            }
        }

        vector<pair<int, int>> directions({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

        vector<vector<int>> distance(n, vector<int>(m, -1));

        while (!q.empty())
        {
            auto [i, j, dist] = q.front();
            q.pop();

            if (distance[i][j] != -1)
                continue;
            distance[i][j] = dist;

            for (auto &direction : directions)
            {
                auto [di, dj] = direction;
                int ii = i + di;
                int jj = j + dj;

                if (ii >= 0 && ii < n && jj >= 0 && jj < m)
                {
                    q.push({ii, jj, dist + 1});
                }
            }
        }
        return distance;
    }
};