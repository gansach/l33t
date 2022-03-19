class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> ans;
        string start = s.substr(0, 2);
        string end = s.substr(3, 2);
        int start_digit = start.back() - '0';
        int end_digit = end.back() - '0';
        for (char c = start.front(); c != end.front() + 1; c++)
        {
            for (int i = start_digit; i <= end_digit; i++)
            {
                string tmp;
                tmp.push_back(c);
                tmp.push_back(i + '0');
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};