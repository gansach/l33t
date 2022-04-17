class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] = digits[i] + carry;
            carry = digits[i] / 10;
            if (carry)
                digits[i] %= 10;
        }

        if (carry)
        {
            digits.resize(digits.size() + 1);

            for (int i = digits.size() - 1; i >= 1; i--)
                digits[i] = digits[i - 1];

            digits[0] = 1;
        }
        return digits;
    }
};