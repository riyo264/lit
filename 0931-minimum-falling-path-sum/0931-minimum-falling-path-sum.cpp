class Solution {
public:
    void maxpath(int n, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        for(int i = 0; i < n; i++)
        {
            dp[n-1][i] = mat[n-1][i];
        }
        for(int i = n-2; i > -1; i--)
        {
            for(int j = n-1; j > -1; j--)
            {
                int down = INT_MAX;
                int left = INT_MAX;
                int right = INT_MAX;
                down = mat[i][j] + dp[i+1][j];
                if(j > 0)left = mat[i][j] + dp[i+1][j-1];
                if(j < n-1)right = mat[i][j] + dp[i+1][j+1];
                dp[i][j] = min(min(left, right), down);
            }
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        maxpath(n, dp, matrix);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};