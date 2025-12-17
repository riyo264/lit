class Solution {
public:
    int solve(int i, int flag, int& profit, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(i == n) {
            return 0;
        }
        if(dp[i][flag] != -1) {
            return dp[i][flag];
        }
        if(flag) {
            profit = max(solve(i+1, 0, profit, prices, dp)-prices[i], solve(i+1, 1, profit, prices, dp));
        }
        else {
            profit = max(solve(i+1, 1, profit, prices, dp)+prices[i], solve(i+1, 0, profit, prices, dp));
        }
        return dp[i][flag] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, profit, prices, dp);
    }
};