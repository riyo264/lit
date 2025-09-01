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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet ds(n);
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++) 
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                }
                else {
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }

        vector<vector<string>> mergeMail(n);
        for(auto it : mpp) 
        {
            string mail = it.first;
            int idx = ds.findPar(it.second);
            mergeMail[idx].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};