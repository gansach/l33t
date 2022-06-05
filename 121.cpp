class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minTillNow = prices.front();
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minTillNow = min(minTillNow, prices[i]);
            profit = max(profit, prices[i] - minTillNow);
        }
        return profit;
    }
};