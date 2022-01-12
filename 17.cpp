class Solution
{
public:
    void generate(int i, string digits, string combination, map<int, string> digit2char, vector<string> &combinations)
    {
        if (i == digits.size())
        {
            combinations.push_back(combination);
            return;
        }

        for (auto c : digit2char[digits[i] - '0'])
        {
            combination.push_back(c);
            generate(i + 1, digits, combination, digit2char, combinations);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations;
        if (digits.empty())
            return combinations;

        map<int, string> digit2char;
        char c = 'a';
        for (int i = 2; i <= 9; i++)
        {
            int cnt = 3;
            if (i == 7 || i == 9)
                cnt++;
            while (cnt--)
                digit2char[i].push_back(c++);
        }
        generate(0, digits, "", digit2char, combinations);
        return combinations;
    }
};