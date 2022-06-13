class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int itr1 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
                itr1 = max(itr1 - 1, 0);
            else
                s[itr1++] = s[i];
        }

        int itr2 = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
                itr2 = max(itr2 - 1, 0);
            else
                t[itr2++] = t[i];
        }

        if (itr1 != itr2)
            return false;
        for (int i = 0; i < itr1; i++)
            if (s[i] != t[i])
                return false;

        return true;
    }
};

// Without chaning string, iterating from back
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int si = s.size() - 1, ti = t.size() - 1;
        int back_s = 0, back_t = 0;

        while (si >= 0 || ti >= 0)
        {
            while (si >= 0)
            {
                if (s[si] == '#')
                {
                    back_s++;
                    si--;
                }
                else if (back_s > 0)
                {
                    back_s--;
                    si--;
                }
                else
                    break;
            }

            while (ti >= 0)
            {
                if (t[ti] == '#')
                {
                    back_t++;
                    ti--;
                }
                else if (back_t > 0)
                {
                    back_t--;
                    ti--;
                }
                else
                    break;
            }

            if ((si < 0 && ti >= 0) || (si >= 0 && ti < 0))
                return false;
            if ((si >= 0 && ti >= 0) && (s[si] != t[ti]))
                return false;
            si--;
            ti--;
        }
        return true;
    }
};