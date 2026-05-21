class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        if(i >= m || j >= n) {
            return 1e5;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int p1 = grid[i][j] + solve(i+1, j, grid, dp);
        int p2 = grid[i][j] + solve(i, j+1, grid, dp);
        int path = min(p1, p2);
        return dp[i][j] = path;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(0, 0, grid, dp);
    }
};