class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {

        int i = 0, j = 0;
        vector<vector<int>> intersections;
        while (i < firstList.size() && j < secondList.size())
        {
            int fx = firstList[i][0], fy = firstList[i][1];
            int sx = secondList[j][0], sy = secondList[j][1];

            int l = max(fx, sx);
            int h = min(fy, sy);

            if (l <= h)
                intersections.push_back({l, h});

            fy < sy ? i++ : j++;
        }
        return intersections;
    }
};