class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        grid[i][j] = 0;
        vector<int> del_row = {0, 1, 0, -1};
        vector<int> del_col = {1, 0, -1, 0};
        for(int k = 0; k < 4; k++)
        {
            int newr = i + del_row[k];
            int newc = j + del_col[k];
            if(newr > -1 && newr < n && newc > -1 && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 1) {
                dfs(newr, newc, grid, vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m, 0));
        for(int i = 0; i < m; i++)
        {
            if(grid[0][i] == 1 && vis[0][i] == 0) {
                dfs(0, i, grid, vis);
            }
            if(grid[n-1][i] == 1 && vis[n-1][i] == 0) {
                dfs(n-1, i, grid, vis);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i, 0, grid, vis);
            }
            if(grid[i][m-1] == 1 && vis[i][m-1] == 0) {
                dfs(i, m-1, grid, vis);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++) 
            {
                if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


// BFS APPROACH DECREASES THE TIME

// class Solution {
// private:
//     void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         vis[i][j] = 1;
//         grid[i][j] = 0;

//         vector<int> del_row = {0, 1, 0, -1};
//         vector<int> del_col = {1, 0, -1, 0};

//         while (!q.empty()) {
//             auto [r, c] = q.front();
//             q.pop();

//             for (int k = 0; k < 4; k++) {
//                 int newr = r + del_row[k];
//                 int newc = c + del_col[k];
//                 if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
//                     vis[newr][newc] == 0 && grid[newr][newc] == 1) {
//                     vis[newr][newc] = 1;
//                     grid[newr][newc] = 0;
//                     q.push({newr, newc});
//                 }
//             }
//         }
//     }

// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for (int j = 0; j < m; j++) {
//             if (grid[0][j] == 1 && vis[0][j] == 0) bfs(0, j, grid, vis);
//             if (grid[n - 1][j] == 1 && vis[n - 1][j] == 0) bfs(n - 1, j, grid, vis);
//         }

//         for (int i = 0; i < n; i++) {
//             if (grid[i][0] == 1 && vis[i][0] == 0) bfs(i, 0, grid, vis);
//             if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0) bfs(i, m - 1, grid, vis);
//         }

//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 1) cnt++;
//             }
//         }
//         return cnt;
//     }
// };
