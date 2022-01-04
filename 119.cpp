class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        using ll = long long;

        int num_terms = rowIndex + 1;

        vector<int> terms({1});
        for (int i = 1; i < num_terms; i++)
        {
            ll term = ((ll)terms.back() * (rowIndex - i + 1)) / i;
            terms.push_back(term);
        }
        return terms;
    }
};

/*
class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    int nCr(int n, int r)
    {
        r = min(r, n - r);
        int num = 1, denom = 1;
        while (r)
        {
            num *= n--;
            denom *= r--;
            int g = gcd(num, denom);
            num /= g;
            denom /= g;
        }
        return num / denom;
    }
    vector<int> getRow(int rowIndex)
    {
        vector<int> pascal;
        for (int i = 0; i <= rowIndex; i++)
        {
            pascal.push_back(nCr(rowIndex, i));
        }
        return pascal;
    }
};
*/