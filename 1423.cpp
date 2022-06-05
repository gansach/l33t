// Prefix sum && Suffix sum
// O(1)
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int lsum = 0;
        for (int i = 0; i < k; i++)
            lsum += cardPoints[i];

        int ans = lsum;
        int rsum = 0;

        int j = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[j--];
            ans = max(ans, lsum + rsum);
        }
        return ans;
    }
};