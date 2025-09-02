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

    // void unionByRank(int u, int v) {
    //     int ultP_u = findPar(u);
    //     int ultP_v = findPar(v);
    //     if(ultP_u == ultP_v) return;
    //     if(ultP_u < ultP_v) {
    //         parent[ultP_u] = ultP_v;
    //     }
    //     else if(ultP_u > ultP_v) {
    //         parent[ultP_v] = ultP_u;
    //     }
    //     else {
    //         parent[ultP_u] = ultP_v;
    //         rank[ultP_u]++;
    //     }
    // }

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
private:
    bool isValid(int n, int m, int& size) {
        return n < size && n >= 0 && m < size && m >= 0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0;
        DisJointSet ds(n*n);

        // 1s Component are made using DSU
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                if(grid[i][j] == 0) continue;
                vector<int> dr = {-1, 0, 1, 0};
                vector<int> dc = {0, -1, 0, 1};
                for(int d = 0; d < 4; d++) {
                    int newr = i + dr[d];
                    int newc = j + dc[d];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int node = (i*n) + j;
                        int adjNode = (newr * n) + newc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        // Converting one 0 to 1 and finding the largest 1 component
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1) continue;
                set<int> Uparents;
                vector<int> dr = {-1, 0, 1, 0};
                vector<int> dc = {0, -1, 0, 1};
                for(int d = 0; d < 4; d++) {
                    int newr = i + dr[d];
                    int newc = j + dc[d];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int node = i*n + j;
                        int adjNode = newr*n + newc;
                        Uparents.insert(ds.findPar(adjNode));
                    }
                }
                int total = 0;
                for(auto it : Uparents)
                {
                    total += ds.size[it];
                }
                sum = max(total+1, sum);
            }
        }
        for(int i = 0; i < n*n; i++)
        {
            sum = max(sum, ds.size[ds.findPar(i)]); 
        }
        return sum;
    }
};