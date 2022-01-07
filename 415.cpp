class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int size = min(num1.size(), num2.size());

        string result;

        int carry = 0;
        for (int i = 0; i < size; i++)
        {
            int d1 = num1[i] - '0';
            int d2 = num2[i] - '0';

            int d = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;

            result.push_back(d + '0');
        }

        for (int i = size; i < num1.size(); i++)
        {
            int d1 = num1[i] - '0';
            int d = (d1 + carry) % 10;
            carry = (d1 + carry) / 10;
            result.push_back(d + '0');
        }

        for (int i = size; i < num2.size(); i++)
        {
            int d2 = num2[i] - '0';
            int d = (d2 + carry) % 10;
            carry = (d2 + carry) / 10;
            result.push_back(d + '0');
        }

        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());

        return result;
    }
};