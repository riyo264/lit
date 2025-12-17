class Solution {
public:
    int solve(int i, int flag, int n, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(i == n || cap == 0) {
            return 0;
        }
        if(dp[i][flag][cap] != -1) {
            return dp[i][flag][cap];
        }
        int profit = 0;
        if(flag) {
            profit = max(solve(i+1, 0, n, cap, prices, dp)-prices[i], solve(i+1, 1, n, cap, prices, dp));
        }
        else    {
            profit = max(solve(i+1, 1, n, cap-1, prices, dp)+prices[i], solve(i+1, 0, n, cap, prices, dp));
        }
        return dp[i][flag][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, n, 2, prices, dp);
    }
};