class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto &road: roads) {
            int s = road.front(), d = road.back();
            degree[s]++;
            degree[d]++;
        }
        vector<pair<int, int>> degreePairs;
        
        for(int i = 0; i < n; i++) {
            degreePairs.push_back({degree[i], i});
        }
        
        sort(degreePairs.begin(), degreePairs.end());
        
        map<int, int> valueMap;
        
        int value = 1;
        for(auto itr: degreePairs) {
            valueMap[itr.second] = value++;
        }
        
        long long ans = 0;
        for(auto& road: roads) {
            int s = road.front(), d = road.back();
            ans += valueMap[s] + valueMap[d];
        }
        return ans;
    }
};