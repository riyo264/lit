class Solution {
public:
    // int solve(int i, int flag, vector<int>& prices, vector<vector<int>>& dp) {
    //     int n = prices.size();
    //     if(i == n) {
    //         return 0;
    //     }
    //     if(dp[i][flag] != -1) {
    //         return dp[i][flag];
    //     }
    //     int profit = 0;
    //     if(flag) {
    //         profit = max(solve(i+1, 0, prices, dp)-prices[i], solve(i+1, 1, prices, dp));
    //     }
    //     else {
    //         profit = max(solve(i+1, 1, prices, dp)+prices[i], solve(i+1, 0, prices, dp));
    //     }
    //     return dp[i][flag] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);

        vector<vector<int>> tab(n+1, vector<int>(2, 0));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < 2; j++)
            {
                int profit = 0;
                if(j) {
                    profit = max(tab[i+1][0]-prices[i], tab[i+1][1]);
                }
                else {
                    profit = max(tab[i+1][1]+prices[i], tab[i+1][0]);
                }
                tab[i][j] = profit;
            }
        }
        return tab[0][1];
    }
};