class Solution {
public:
    int shortestPath(vector<vector<vector<int>>>& G, int n){
        vector<bool> vis(n, false);
        vector<int> dist(n, 1e9);
        
        priority_queue<vector<int>> Q;
        Q.push({0, 0});
        dist[0] = 0;
        while(!Q.empty()){
            vector<int> t = Q.top();
            int u = t[1];
            Q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto it : G[u]){
                if(dist[u] + it[1] < dist[it[0]]){
                    dist[it[0]] = dist[u] + it[1];
                    Q.push({-dist[it[0]], it[0]});
                }
            }
        }
        if(dist[n - 1] == 1e9) return -1;
        return dist[n - 1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj;
        adj.resize(n);
        for(auto it : edges) 
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2 * it[2]});
        }
        return shortestPath(adj, n);
    }
};