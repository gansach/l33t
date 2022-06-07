// Since this number system does not have a 0 it's like 9 is succeeded by 11
// So we need to reduce the columnNumber by 1 for every iteration
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber)
        {
            columnNumber--;
            ans.push_back((columnNumber % 26) + 'A');
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};