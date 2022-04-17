namespace
{
    pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b)
    {
        return {a.first + b.first, a.second + b.second};
    }
    pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b)
    {
        return {a.first - b.first, a.second - b.second};
    }
}

class Solution
{
public:
    int maxTrailingZeros(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.front().size();

        using pii = pair<int, int>;
        using vpii = vector<pii>;
        using vvpii = vector<vpii>;

        // grid[i][j] = x
        // factor25[i][j] = [t, f]
        // x = 2t + 5f + ...
        vvpii factor25(n, vpii(m, {0, 0}));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int x = grid[i][j];
                int t = 0, f = 0;

                while (x % 2 == 0)
                {
                    x /= 2;
                    t++;
                }
                while (x % 5 == 0)
                {
                    x /= 5;
                    f++;
                }

                factor25[i][j] = {t, f};
            }
        }

        // prefix, suffix
        vvpii left(n, vpii(m, {0, 0})), right(n, vpii(m, {0, 0}));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                    left[i][j] = factor25[i][j];
                else
                    left[i][j] = left[i][j - 1] + factor25[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (j == m - 1)
                    right[i][j] = factor25[i][j];
                else
                    right[i][j] = right[i][j + 1] + factor25[i][j];
            }
        }

        int maxTrailing0s = 0;

        // max trailing up-left, up-right
        for (int j = 0; j < m; j++)
        {
            auto up = factor25[0][j];
            for (int i = 0; i < n; i++)
            {
                if (i > 0)
                    up = up + factor25[i][j];

                auto [ul2, ul5] = up + left[i][j] - factor25[i][j];
                auto [ur2, ur5] = up + right[i][j] - factor25[i][j];

                maxTrailing0s = max({maxTrailing0s, min(ul2, ul5), min(ur2, ur5)});
            }
        }

        // max trailing down-left, down-right
        for (int j = 0; j < m; j++)
        {
            auto down = factor25[n - 1][j];
            for (int i = n - 1; i >= 0; i--)
            {
                if (i < n - 1)
                    down = down + factor25[i][j];

                auto [dl2, dl5] = down + left[i][j] - factor25[i][j];
                auto [dr2, dr5] = down + right[i][j] - factor25[i][j];

                maxTrailing0s = max({maxTrailing0s, min(dl2, dl5), min(dr2, dr5)});
            }
        }

        return maxTrailing0s;
    }
};