class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        char a = pattern[0], b = pattern[1];

        if (a == b)
        {
            long long cnt = count(text.begin(), text.end(), a);
            if (cnt == 0)
                return 0;
            return (cnt * (cnt + 1)) / 2;
        }

        string text1 = text + b;
        string text2 = a + text;

        long long cnt1 = 0, a_count = 0;
        for (int i = 0; i < text1.size(); i++)
        {
            char c = text1[i];
            if (c == a)
            {
                a_count++;
            }
            else if (c == b)
            {
                cnt1 += a_count;
            }
        }

        long long cnt2 = 0, b_count = 0;
        for (int i = text2.size() - 1; i >= 0; i--)
        {
            char c = text2[i];
            if (c == b)
            {
                b_count++;
            }
            else if (c == a)
            {
                cnt2 += b_count;
            }
        }

        cout << cnt1 << " " << cnt2 << endl;
        return max(cnt1, cnt2);
    }
};