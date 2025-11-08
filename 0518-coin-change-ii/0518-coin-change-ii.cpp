class Solution {
public:
    int solve(int amount, int i, vector<int>& coins, vector<vector<int>>& dp) {
        if(i == 0) {
            if(amount == 0) {
                return 1;
            }
        }
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int notTake = 0;
        if(i > 0) {
            notTake = solve(amount, i-1, coins, dp);
        }
        int Take = 0;
        if(amount >= coins[i]) {
            Take = solve(amount - coins[i], i, coins, dp);
        }
        return dp[i][amount] = Take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(amount, n-1, coins, dp);
        // const long long MOD = 1e9 + 7;
        // for(int i = 0; i <= amount; i++) 
        // {
        //     dp[0][i] = (i % coins[0] == 0);
        // }

        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = 0; j <= amount; j++) 
        //     {
        //         long long notTake = dp[i-1][j];
        //         long long Take = 0;
        //         if(j >= coins[i]) {
        //             Take = dp[i][j - coins[i]];
        //         }
        //         dp[i][j] = (Take + notTake) % MOD;
        //     }
        // }
        // return (int)dp[n-1][amount];
    }
};