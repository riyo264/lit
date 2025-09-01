class DisJointSet {
    vector<int> rank, parent, size;
public:
    DisJointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultP_u = findPar(u);
        int ultP_v = findPar(v);
        if(ultP_u == ultP_v) return;
        if(ultP_u < ultP_v) {
            parent[ultP_u] = ultP_v;
        }
        else if(ultP_u > ultP_v) {
            parent[ultP_v] = ultP_u;
        }
        else {
            parent[ultP_u] = ultP_v;
            rank[ultP_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ultP_u = findPar(u);
        int ultP_v = findPar(v);
        if(ultP_u == ultP_v) return;
        if(ultP_u > ultP_v) {
            parent[ultP_v] = ultP_u;
            size[ultP_u] += size[ultP_v];
        }
        else {
            parent[ultP_u] = ultP_v;
            size[ultP_v] += size[ultP_u];
        }
    }
};    

class Solution {
    void dfs(int node, vector<vector<int>>& given, vector<int>& vis) {
        vis[node] = 1;
        for(auto it: given[node]) 
        {
            if(vis[it] == 0) {
                dfs(it, given, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<vector<int>> adjLS(n);
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(isConnected[i][j] == 1 && i != j) {
        //             adjLS[i].push_back(j);
        //             adjLS[j].push_back(i);
        //         }
        //     }
        // }
        // vector<int> vis(n, 0);
        // int cnt = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     if(vis[i] == 0) {
        //         cnt++;
        //         dfs(i, adjLS, vis);
        //     }
        // }
        // return cnt;

        // DISJOINT SET APPROACH
        DisJointSet ds(n);
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findPar(i) == i) {
                cnt++;
            }
        }
        return cnt;
    }
};