class DisJointSet {
public:
    vector<int> rank, parent, size;
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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extraEdges = 0;
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findPar(u) == ds.findPar(v)) {
                extraEdges++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int c = 0;
        for(int i = 0; i < n; i++) 
        {
            if(ds.parent[i] == i) {
                c++;
            }
        }
        int ans = c - 1;
        if(extraEdges < ans) {
            return -1;
        }
        else {
            return ans;
        }
    }
};