class Solution
{
public:
    bool search(vector<vector<char>> &board, int i, int j, string &word, int k)
    {
        int n = board.size(), m = board.front().size();

        if (k == word.size())
            return true;

        if (!(i >= 0 && i < n && j >= 0 && j < m))
            return false;

        if (board[i][j] == '*')
            return false;

        if (board[i][j] != word[k])
            return false;

        board[i][j] = '*';
        bool found = search(board, i - 1, j, word, k + 1) ||
                     search(board, i + 1, j, word, k + 1) ||
                     search(board, i, j - 1, word, k + 1) ||
                     search(board, i, j + 1, word, k + 1);
        board[i][j] = word[k];
        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board.front().size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word.front())
                {
                    if (search(board, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};