class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (left >> i != right >> i)
                break;
            else
                ans |= ((left >> i) << i);
        }
        return ans;
    }
};