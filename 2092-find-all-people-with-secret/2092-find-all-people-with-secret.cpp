class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int m = meetings.size();
        map<int, vector<pair<int, int>>> mpp;
        for(int i = 0; i < m; i++) {
            pair<int, int> p = {meetings[i][0], meetings[i][1]};
            int key = meetings[i][2];
            mpp[key].push_back(p);
        }
        vector<int> secret(n, 0);
        vector<int> ans;
        secret[0] = secret[firstPerson] = 1;
        for(auto& it : mpp) {
            auto& p = it.second;
            unordered_map<int, vector<int>> g;
            unordered_set<int> s;
            for(auto& x : p) {
                int a = x.first;
                int b = x.second;
                g[a].push_back(b);
                g[b].push_back(a);
                s.insert(a);
                s.insert(b);
            }
            queue<int> q;
            unordered_set<int> vis;
            for(int x : s) 
            {
                if(secret[x]) {
                    q.push(x);
                }
            }
            while(!q.empty())
            {
                int person = q.front();
                q.pop();
                if(vis.count(person)) continue;
                vis.insert(person);
                for(int x : g[person]) {
                    if(!secret[x]) q.push(x);
                    secret[x] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(secret[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};