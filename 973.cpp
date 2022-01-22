class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        using tlii = tuple<long long, int, int>;

        priority_queue<tlii, vector<tlii>, greater<tlii>> pq;
        for (auto &point : points)
        {
            long long x = point[0], y = point[1];
            pq.push({x * x + y * y, x, y});
        }

        vector<vector<int>> result;
        for (int i = 0; i < k; i++)
        {
            auto [dist, x, y] = pq.top();
            result.push_back({x, y});
            pq.pop();
        }
        return result;
    }
};