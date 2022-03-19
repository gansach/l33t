// BFS
class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image.front().size();

        vector<pair<int, int>> directions({{0, 1}, {1, 0}, {-1, 0}, {0, -1}});

        queue<pair<int, int>> q({{sr, sc}});
        int srcColor = image[sr][sc];

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (image[i][j] == -1)
                continue;
            image[i][j] = -1;

            for (auto d : directions)
            {
                int ii = i + d.first, jj = j + d.second;
                if (isSafe(ii, jj, n, m) && image[ii][jj] == srcColor)
                    q.push({ii, jj});
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (image[i][j] == -1)
                    image[i][j] = newColor;
        }
        return image;
    }
};

// DFS
class Solution
{
public:
    void dfs(int i, int j, int srcColor, vector<vector<int>> &image)
    {
        int n = image.size();
        int m = image.front().size();

        if ((i >= 0 && i < n && j >= 0 && j < m) && image[i][j] == srcColor)
        {
            image[i][j] = -1;
            dfs(i + 1, j, srcColor, image);
            dfs(i - 1, j, srcColor, image);
            dfs(i, j - 1, srcColor, image);
            dfs(i, j + 1, srcColor, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        dfs(sr, sc, image[sr][sc], image);
        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[i].size(); j++)
            {
                if (image[i][j] == -1)
                    image[i][j] = newColor;
            }
        }
        return image;
    }
};