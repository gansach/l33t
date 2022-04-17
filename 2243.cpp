class Solution
{
public:
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string t;
            for (int i = 0; i < s.size(); i += k)
            {
                int sum = 0;
                for (auto c : s.substr(i, k))
                    sum += c - '0';
                t += to_string(sum);
            }
            s = t;
        }
        return s;
    }
};