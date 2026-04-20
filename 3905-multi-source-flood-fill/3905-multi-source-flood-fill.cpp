class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for(auto &s : sources) {
            grid[s[0]][s[1]] = s[2];
            q.push({s[0], s[1]});
        }
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            int l = q.size();
            unordered_map<int,int> mp;
            while(l--) {
                auto [x,y] = q.front(); q.pop();
                int c = grid[x][y];
                for(auto &d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0) {
                        int key = nx*m + ny;
                        mp[key] = max(mp[key], c);
                    }
                }
            }
            for(auto &it : mp) {
                int key = it.first, c = it.second;
                int x = key / m, y = key % m;
                grid[x][y] = c;
                q.push({x,y});
            }
        }
        return grid;
    }
};