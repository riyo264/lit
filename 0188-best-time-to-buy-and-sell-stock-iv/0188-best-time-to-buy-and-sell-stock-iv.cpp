class Solution {
public:
    // int solve(int i, int transactions, int k, vector<int>& prices, vector<vector<int>>& dp) {
    //     int n = prices.size();
    //     if(i == n || transactions == 2*k) {
    //         return 0;
    //     }
    //     if(dp[i][transactions] != -1) {
    //         return dp[i][transactions];
    //     }
    //     int profit = 0;
    //     if(transactions % 2 == 0) {
    //         profit = max(-prices[i]+solve(i+1, transactions+1, k, prices, dp), solve(i+1, transactions, k, prices, dp));
    //     }
    //     else {
    //         profit = max(prices[i] + solve(i+1, transactions+1, k, prices, dp), solve(i+1, transactions, k, prices, dp));
    //     }
    //     return dp[i][transactions] = profit;
    // }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2*k, -1));
        // return solve(0, 0, k, prices, dp);

        // vector<vector<int>> tab(n+1, vector<int>(2*k + 1, 0));

        vector<int> cur(2*k + 1, 0), after(2*k + 1, 0);
        for(int i = n-1; i >= 0; i--) 
        {
            for(int transactions = 2*k-1; transactions >= 0; transactions--)
            {
                int profit = 0;
                if(transactions % 2 == 0) {
                    profit = max(-prices[i]+after[transactions+1], after[transactions]);
                }
                else {
                    profit = max(prices[i] + after[transactions+1], after[transactions]);
                }
                cur[transactions] = profit;
            }
            after = cur;
        }
        return after[0];
    }
};