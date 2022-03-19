class Solution
{
public:
    int halveArray(vector<int> &nums)
    {

        double sum = accumulate(nums.begin(), nums.end(), (double)0);
        double half_sum = sum / 2;

        priority_queue<double> pq(nums.begin(), nums.end());

        int cnt = 0;
        while (sum > half_sum)
        {
            double m = pq.top();
            pq.pop();

            sum -= m / 2;
            pq.push(m / 2);

            cnt++;
        }
        return cnt;
    }
};