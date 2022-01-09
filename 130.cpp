class Solution
{
public:
    void bfs(int si, int sj, vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board.front().size();

        board[si][sj] = 'Z';

        vector<pair<int, int>> directions({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

        using pii = pair<int, int>;
        queue<pii> q({{si, sj}});

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            for (auto &d : directions)
            {
                auto [dx, dy] = d;
                int ii = i + dx;
                int jj = j + dy;

                if ((ii >= 0 && jj >= 0 && ii < n && jj < m) && board[ii][jj] == 'O')
                {
                    q.push({ii, jj});
                    board[ii][jj] = 'Z';
                }
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {

        int n = board.size();
        int m = board.front().size();

        for (auto i : {0, n - 1})
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    bfs(i, j, board);
                }
            }
        }

        for (auto j : {0, m - 1})
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i][j] == 'O')
                {
                    bfs(i, j, board);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = (board[i][j] == 'Z' ? 'O' : 'X');
            }
        }
    }
};