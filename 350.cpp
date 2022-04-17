class Solution
{
public:
    // map
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        map<int, int> freq;
        for (auto num : nums1)
            freq[num]++;

        vector<int> intersection;
        for (auto num : nums2)
        {
            if (freq[num])
            {
                intersection.push_back(num);
                freq[num]--;
            }
        }
        return intersection;
    }

    // sort
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersection;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                intersection.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return intersection;
    }
};