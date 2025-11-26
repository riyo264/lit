class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(vector<vector<int>>& grid, int sum, int k, int i, int j, int m, int n, vector<vector<vector<int>>>& dp) {
        if(i >= m || j >= n) {
            return 0;
        }
        sum = (sum + grid[i][j])%k;
        if(dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }
        if(i == m-1 && j == n-1) {
            if(sum % k == 0) {
                return 1;
            } 
            else {
                return 0;
            }
        }
        int down = 0 + solve(grid, sum, k, i+1, j, m, n, dp);
        int right = 0 + solve(grid, sum, k, i, j+1, m, n, dp);
        return dp[i][j][sum] = (down + right)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        int sum = 0;
        int ans = solve(grid, sum, k, 0, 0, m, n, dp);
        return ans;
    }
};