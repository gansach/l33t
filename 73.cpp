class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix.front().size();

        bool row0 = false, col0 = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Setting col
                    matrix[0][j] = 0; // Setting row
                    if (i == 0)
                        row0 = true;
                    if (j == 0)
                        col0 = true;
                }
            }
        }

        // If first element of row = 0, whole row = 0
        for (int i = 1; i < n; i++)
        {
            if (matrix[i][0] == 0)
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
        }

        // If first element of col = 0, whole col = 0
        for (int j = 1; j < m; j++)
        {
            if (matrix[0][j] == 0)
                for (int i = 1; i < n; i++)
                    matrix[i][j] = 0;
        }

        if (row0)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        if (col0)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};