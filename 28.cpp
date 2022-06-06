class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
            return -1;

        for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
        {
            if (haystack[i] == needle.front())
            {
                bool found = true;
                for (int j = 0; j < needle.size(); j++)
                {
                    if (needle[j] != haystack[i + j])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                    return i;
            }
        }
        return -1;
    }
};

// KMP