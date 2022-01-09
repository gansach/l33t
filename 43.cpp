class Solution
{
public:
    string add(string s, string t)
    {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());

        int size = min(s.size(), t.size());

        int carry = 0;
        string result;

        for (int i = 0; i < size; i++)
        {
            int d1 = s[i] - '0';
            int d2 = t[i] - '0';
            int d = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            result.push_back(d + '0');
        }

        for (int i = size; i < s.size(); i++)
        {
            int d1 = s[i] - '0';
            int d = (d1 + carry) % 10;
            carry = (d1 + carry) / 10;
            result.push_back(d + '0');
        }

        for (int i = size; i < t.size(); i++)
        {
            int d2 = t[i] - '0';
            int d = (d2 + carry) % 10;
            carry = (d2 + carry) / 10;
            result.push_back(d + '0');
        }

        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return result;
    }

    string digitMultiply(string s, int x, int zeros)
    {
        reverse(s.begin(), s.end());
        int carry = 0;
        string result;

        for (auto c : s)
        {
            int d = (c - '0') * x + carry;
            carry = d / 10;
            result.push_back(d % 10 + '0');
        }

        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());

        for (int i = 0; i < zeros; i++)
            result.push_back('0');
        return result;
    }

    string multiply(string num1, string num2)
    {
        vector<string> arr;
        int zeros = 0;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            arr.push_back(digitMultiply(num2, num1[i] - '0', zeros));
            zeros++;
        }

        string ans = "0";
        for (auto itr : arr)
            ans = add(ans, itr);

        for (auto c : ans)
            if (c != '0')
                return ans;

        return "0";
    }
};