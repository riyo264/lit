class Solution {
public:
    // int solve(int i, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
    //     int n = prices.size();
    //     if(i == n) {
    //         return 0;
    //     }
    //     if(dp[i][buy] != -1) {
    //         return dp[i][buy];
    //     }
    //     int profit = 0;
    //     if(buy) {
    //        return dp[i][buy] = profit = max(-prices[i]+solve(i+1, 0, fee, prices, dp), 0+solve(i+1, 1, fee, prices, dp));
    //     }
    //     return dp[i][buy] = profit = max(prices[i]+solve(i+1, 1, fee, prices, dp)-fee, 0+solve(i+1, 0, fee, prices, dp));
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, fee, prices, dp);

        // vector<vector<int>> tab(n+1, vector<int>(2, 0));
        // vector<int> cur(2, 0), after(2, 0);
        // for(int i = n-1; i >= 0; i--) 
        // {
        //     for(int j = 0; j < 2; j++)
        //     {
        //         if(j) {
        //             cur[j] = max(-prices[i]+after[0], 0+after[1]);
        //             }
        //         else {
        //             cur[j] = max(prices[i]+after[1]-fee, 0+after[0]);
        //         }
        //     }
        //     after = cur;
        // }
        // return after[1];

        int buy = INT_MAX, maxi = 0;

        for(auto price: prices){
            if(price-fee > buy){
                maxi += price-fee-buy;
                buy = price-fee;
            }
            buy = min(buy, price);
        }
        return maxi;
    }
};