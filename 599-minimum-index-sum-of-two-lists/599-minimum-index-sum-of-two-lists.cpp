class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> idx;
        for(int i = 0; i < list1.size(); i++) {
            if (idx.find(list1[i]) == idx.end())
                idx[list1[i]] = i;
        }
        
        
        for(int j = 0; j < list2.size(); j++) {
            if (idx.find(list2[j]) != idx.end()) {
                idx[list2[j] + "#"] = idx[list2[j]] + j;
            }
        }
        
        for(auto itr: idx) {
            cout << itr.first << " " << itr.second << "\n";
        }
        
        int min_i = INT_MAX;
        for(auto itr: idx) {
            if (itr.first.back() == '#') {
                min_i = min(min_i, itr.second);
            }
        }
        
        vector<string> ans;
        for(auto itr: idx) {
            if (itr.first.back() == '#' && itr.second == min_i) {
                ans.push_back(itr.first);
            }
        }
        for(auto& i: ans) i.pop_back();
        return ans;
    }
};