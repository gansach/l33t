class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = 0, r = matrix.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                l = mid + 1;
            else if (matrix[mid][0] > target)
                r = mid - 1;
        }

        auto &row = matrix[max(r, 0)];
        l = 0, r = row.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (row[mid] == target)
                return true;
            else if (row[mid] < target)
                l = mid + 1;
            else if (row[mid] > target)
                r = mid - 1;
        }
        return false;
    }
};