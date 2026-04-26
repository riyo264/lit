class Solution {
public:
    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        char src = grid[r][c];
        vis[r][c] = 1;
        vector<int> delr = {-1, 0, 1, 0};
        vector<int> delc = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++)
        {
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if((nrow != pr || ncol != pc) && nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == src) {
                if(vis[nrow][ncol] == 1) {
                    return true;
                }
                if(dfs(nrow, ncol, r, c, grid, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(vis[i][j] == 0 && dfs(i, j, -1, -1, grid, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};