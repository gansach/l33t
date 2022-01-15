class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        m--, n--;

        int N = m + n;
        int r = min(m, n);

        long long num = 1;
        long long denom = 1;
        while (r)
        {
            num *= N;
            denom *= r;
            N--;
            r--;
        }
        return num / denom;
    }
};
/*
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            paths[i][0] = 1;
        for (int j = 0; j < n; j++)
            paths[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths.back().back();
    }
};
*/