class Solution {
public:
    int solve(int i, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(i == n) {
            return 0;
        }
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int profit = 0;
        if(buy) {
           return dp[i][buy] = profit = max(-prices[i]+solve(i+1, 0, fee, prices, dp), 0+solve(i+1, 1, fee, prices, dp));
        }
        return dp[i][buy] = profit = max(prices[i]+solve(i+1, 1, fee, prices, dp)-fee, 0+solve(i+1, 0, fee, prices, dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};