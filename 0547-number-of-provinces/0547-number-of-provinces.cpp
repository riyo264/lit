class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;
        for(auto i : isConnected[node]) {
            if(!vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};