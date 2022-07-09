class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq_stones;
        for (auto stone : stones)
            pq_stones.push(stone);

        while (pq_stones.size() >= 2)
        {
            int y = pq_stones.top();
            pq_stones.pop();
            int x = pq_stones.top();
            pq_stones.pop();

            if (x != y)
                pq_stones.push(y - x);
        }

        return pq_stones.size() ? pq_stones.top() : 0;
    }
};