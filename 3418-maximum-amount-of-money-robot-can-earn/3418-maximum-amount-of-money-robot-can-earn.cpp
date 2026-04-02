class Solution {
public:
    int solve(int i, int j, int neutral, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        int m = coins.size();
        int n = coins[0].size();
        if(i >= m || j >= n) {
            return INT_MIN;
        }
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neutral > 0) return 0;
            return coins[i][j];
        }
        if(dp[i][j][neutral] != -1) {
            return dp[i][j][neutral];
        }
        int val = coins[i][j];
        int fin = INT_MIN;
        if(coins[i][j] >= 0) {
            fin = val + max(solve(i+1, j, neutral, coins, dp), solve(i, j+1, neutral, coins, dp));
        }
        else {
            int keep = val + max(solve(i+1, j, neutral, coins, dp), solve(i, j+1, neutral, coins, dp));
            int skip = INT_MIN;
            if(neutral > 0) {
                skip = max(solve(i+1, j, neutral-1, coins, dp), solve(i, j+1, neutral-1, coins, dp));
            }
            fin = max(keep, skip);
        }
        return dp[i][j][neutral] = fin;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int profit = 0;
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(3, INT_MIN)));
        // return solve(0, 0, 2, coins, dp);
        for(int i = 0; i < 3; i++) {
            if(coins[m-1][n-1] < 0 && i > 0)
                dp[m-1][n-1][i] = 0;
            else
                dp[m-1][n-1][i] = coins[m-1][n-1];
        }
        for(int i = m-1; i >= 0; i--) 
        {
            for(int j = n-1; j >= 0; j--) 
            {
                if(i == m-1 && j == n-1) {
                    continue;
                }
                for(int k = 0; k <= 2; k++) 
                {
                    long long val = coins[i][j];
                    long long fin = LLONG_MIN;
                    if(coins[i][j] >= 0) {
                        fin = val + max(dp[i+1][j][k], dp[i][j+1][k]);
                    }
                    else {
                        long long keep = val + max(dp[i+1][j][k], dp[i][j+1][k]);
                        long long skip = INT_MIN;
                        if(k > 0) {
                            skip = max(dp[i+1][j][k-1], dp[i][j+1][k-1]);
                        }
                        fin = max(keep, skip);
                    }
                    dp[i][j][k] = (int)fin;
                }
            }
        }
        return dp[0][0][2];
    }
};