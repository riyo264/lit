class Solution {
public:
    void path(int n, vector<vector<int>>& dp, vector<vector<int>>& a) {
        for(int i = 0; i < n; i++)
        {
            dp[n-1][i] = a[n-1][i];
        }
        for(int i = n-2; i > -1; i--) 
        {
            for(int j = i; j > -1; j--)
            {
                int down = a[i][j] + dp[i+1][j];
                int dia = a[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, dia);
            }
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        path(n, dp, triangle);
        return dp[0][0];
    }
};