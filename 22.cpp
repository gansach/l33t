class Solution
{
public:
    void generate(int l, int r, string parenthesis, vector<string> &parentheses)
    {
        if (l == 0 && r == 0)
        {
            parentheses.push_back(parenthesis);
            return;
        }
        else if (l < 0 || r < 0)
            return;

        parenthesis.push_back('(');
        generate(l - 1, r, parenthesis, parentheses);
        parenthesis.pop_back();

        if (r > l)
        {
            parenthesis.push_back(')');
            generate(l, r - 1, parenthesis, parentheses);
            parenthesis.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> parentheses;
        generate(n, n, "", parentheses);
        return parentheses;
    }
};