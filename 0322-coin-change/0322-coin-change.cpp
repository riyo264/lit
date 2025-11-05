class Solution {
public:
    // int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
    //     if(i == 0) {
    //         if(amount % coins[i] == 0) {
    //             return amount/coins[i];
    //         }
    //         else {
    //             return 1e9;
    //         }
    //     }
    //     if(dp[i][amount] != -1) {
    //         return dp[i][amount];
    //     }
    //     int notTake = 0 + solve(coins, i-1, amount, dp);
    //     int Take = INT_MAX;
    //     if(coins[i] <= amount) {
    //         Take = 1 + solve(coins, i, amount - coins[i], dp);
    //     }
    //     return dp[i][amount] = min(Take, notTake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));  // Take value '0' instead of '-1' for tabulation
        // if(solve(coins, n-1, amount, dp) == 1e9) {
        //     return -1;
        // }
        // return solve(coins, n-1, amount, dp);


        // SPACE OPTIMIZATION
            vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        // TABULATION
        for(int i = 0; i <= amount; i++) 
        {
            if(i % coins[0] == 0) {
                prev[i] = i/coins[0];
            }
            else {
                prev[i] = 1e9;
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++)
            {
                int notTake = 0 + prev[j];
                int Take = INT_MAX;
                if(coins[i] <= j) {
                    Take = 1 + cur[j - coins[i]];
                }
                cur[j] = min(Take, notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};