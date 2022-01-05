class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix.front().size();

        int i = 0, j = m - 1;
        while (j >= 0 && i < n)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
        }
        return false;
    }
};
// n * log(m)
/*
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
*/