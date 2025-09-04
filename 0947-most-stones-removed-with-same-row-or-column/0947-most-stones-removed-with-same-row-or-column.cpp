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
        if(rank[ultP_u] < rank[ultP_v]) {
            parent[ultP_u] = ultP_v;
        }
        else if(rank[ultP_u] > rank[ultP_v]) {
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
        if(size[ultP_u] > size[ultP_v]) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones) 
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisJointSet ds(maxRow + maxCol + 5);
        unordered_map<int, int> stonepos;
        for(auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stonepos[nodeRow] = 1;
            stonepos[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it : stonepos) 
        {
            if(ds.findPar(it.first) == it.first) {
                cnt++;
            }
        }
        return n-cnt;
    }
};