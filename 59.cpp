class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> matrix(n, vector<int>(n, -1));

        pair<int, int> right = {0, 1};
        pair<int, int> down = {-1, 0};
        pair<int, int> left = {0, -1};
        pair<int, int> up = {1, 0};

        vector<pair<int, int>> directions({right, down, left, up});

        int i = 0, j = 0;
        matrix[0][0] = 1;

        bool filled = false;

        while (!filled)
        {

            filled = true;
            for (auto direction : directions)
            {
                auto [ii, jj] = direction;

                while (isSafe(i + ii, j + jj, n, n) && matrix[i + ii][j + jj] == -1)
                {
                    filled = false;

                    matrix[i + ii][j + jj] = matrix[i][j] + 1;

                    i += ii;
                    j += jj;
                }
            }
        }
        return matrix;
    }
};