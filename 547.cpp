class Solution {
public:
    bool dfs(int i, map<int, vector<int>>& adj, vector<bool>& visited) {
        
        if (visited[i]) return false;
        visited[i] = true;
        
        for(auto j: adj[i]) {
            dfs(j, adj, visited);
        }
        
        return true;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        map<int, vector<int>> adj;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (!visited[i] && dfs(i, adj, visited)) ans++;
        }
        return ans;
    }
};