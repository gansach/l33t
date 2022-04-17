class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9], cols[9][9], sqrs[9][9];

        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(sqrs, false, sizeof(sqrs));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                int x = board[i][j] - '1';
                int square = (i / 3) + (j / 3) * 3;

                if (rows[x][i] || cols[x][j] || sqrs[x][square])
                    return false;

                rows[x][i] = true;
                cols[x][j] = true;
                sqrs[x][square] = true;
            }
        }
        return true;
    }
};