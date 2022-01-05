class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int area = INT_MIN;
        while (i < j)
        {
            area = max(area, min(height[j], height[i]) * (j - i));

            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return area;
    }
};