class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans;

        int n = a.size(), m = b.size();
        int carry = 0;

        for (int i = 0; i < min(n, m); i++)
        {
            int x = a[i] - '0', y = b[i] - '0';
            if (x + y + carry == 0)
                ans.push_back('0');
            else if (x + y + carry == 1)
            {
                ans.push_back('1');
                carry = 0;
            }
            else if (x + y + carry == 2)
            {
                ans.push_back('0');
                carry = 1;
            }
            else
                ans.push_back('1');
        }

        for (int i = min(n, m); i < n; i++)
        {
            int x = a[i] - '0';
            if (x + carry == 0)
                ans.push_back('0');
            else if (x + carry == 1)
            {
                ans.push_back('1');
                carry = 0;
            }
            else
                ans.push_back('0');
        }

        for (int i = min(n, m); i < m; i++)
        {
            int y = b[i] - '0';
            if (y + carry == 0)
                ans.push_back('0');
            else if (y + carry == 1)
            {
                ans.push_back('1');
                carry = 0;
            }
            else
                ans.push_back('0');
        }

        if (carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};