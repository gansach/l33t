class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int itr1 = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '#') itr1 = max(itr1 - 1, 0);
            else s[itr1++] = s[i];
        }
        
        int itr2 = 0;
        for(int i = 0; i < t.size(); i++) {
            if (t[i] == '#') itr2 = max(itr2 - 1, 0);
            else t[itr2++] = t[i];
        }
        
        if(itr1 != itr2) return false;
        for(int i = 0; i < itr1; i++)
            if (s[i] != t[i]) return false;
        
        return true;
    }
};