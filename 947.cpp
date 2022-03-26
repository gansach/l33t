// Cantor Pairing: (i, j) -> ((i + j) * (i + j + 1)) / 2 + j
class Solution
{
public:
    int cantor(int i, int j)
    {
        return ((i + j) * (i + j + 1)) / 2 + j;
    }

    int find(int i, map<int, int> &parent)
    {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void join(int i, int j, map<int, int> &parent, map<int, int> &rank)
    {
        i = find(i, parent);
        j = find(j, parent);

        if (i != j)
        {
            if (rank[i] <= rank[j])
            {
                parent[i] = j;
                rank[j] += rank[i];
            }
            else
            {
                parent[j] = i;
                rank[i] += rank[j];
            }
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        map<int, int> parent, rank;

        for (auto &stone : stones)
        {
            int x = cantor(stone[0], stone[1]);
            parent[x] = x;
            rank[x] = 1;
        }

        for (auto &s1 : stones)
        {
            for (auto &s2 : stones)
            {
                int x1 = s1[0], y1 = s1[1];
                int x2 = s2[0], y2 = s2[1];

                if (x1 == x2 || y1 == y2)
                {
                    join(cantor(x1, y1), cantor(x2, y2), parent, rank);
                }
            }
        }

        int ans = 0;
        for (auto itr : parent)
        {
            if (itr.first == itr.second)
                ans++;
        }
        return stones.size() - ans;
    }
};

// Union Find
class Solution
{
public:
    using pii = pair<int, int>;

    pii find(pii i, map<pii, pii> &parent)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void join(pii i, pii j, map<pii, pii> &parent, map<pii, int> &rank)
    {
        i = find(i, parent);
        j = find(j, parent);

        if (i != j)
        {
            if (rank[i] <= rank[j])
            {
                parent[j] = i;
                rank[i] += rank[j];
            }
            else
            {
                parent[j] = j;
                rank[j] += rank[i];
            }
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {

        map<pii, pii> parent;
        for (auto &stone : stones)
        {
            int i = stone[0], j = stone[1];
            parent[{i, j}] = {i, j};
        }

        map<pii, int> rank;

        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = 0; j < stones.size(); j++)
            {
                int x1 = stones[i][0];
                int y1 = stones[i][1];
                int x2 = stones[j][0];
                int y2 = stones[j][1];

                if (x1 == x2 || y1 == y2)
                {
                    join({x1, y1}, {x2, y2}, parent, rank);
                }
            }
        }

        int cnt = 0;
        for (auto &itr : parent)
        {
            if (itr.first == itr.second)
                cnt++;
        }
        return stones.size() - cnt;
    }
};