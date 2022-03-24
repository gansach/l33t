class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool isBoundary(int i, int j, int n, int m)
    {
        return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
    }

    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size();
        int m = maze.front().size();

        int si = entrance[0], sj = entrance[1];

        queue<tuple<int, int, int>> q({{si, sj, 0}});

        vector<pair<int, int>> directions({{0, 1}, {0, -1}, {-1, 0}, {1, 0}});

        while (!q.empty())
        {
            auto [i, j, dist] = q.front();
            q.pop();

            if (maze[i][j] == '+')
                continue;
            maze[i][j] = '+';

            if ((i != si || j != sj) && isBoundary(i, j, n, m))
                return dist;

            for (auto &direction : directions)
            {
                auto [di, dj] = direction;
                int ii = i + di;
                int jj = j + dj;
                if (isSafe(ii, jj, n, m) && maze[ii][jj] == '.')
                {
                    q.push({ii, jj, dist + 1});
                }
            }
        }
        return -1;
    }
};