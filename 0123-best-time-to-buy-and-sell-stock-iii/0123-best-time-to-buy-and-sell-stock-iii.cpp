class Solution {
public:
    // int solve(int i, int flag, int n, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
    //     if(i == n || cap == 0) {
    //         return 0;
    //     }
    //     if(dp[i][flag][cap] != -1) {
    //         return dp[i][flag][cap];
    //     }
    //     int profit = 0;
    //     if(flag) {
    //         profit = max(solve(i+1, 0, n, cap, prices, dp)-prices[i], solve(i+1, 1, n, cap, prices, dp));
    //     }
    //     else    {
    //         profit = max(solve(i+1, 1, n, cap-1, prices, dp)+prices[i], solve(i+1, 0, n, cap, prices, dp));
    //     }
    //     return dp[i][flag][cap] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 1, n, 2, prices, dp);

        vector<vector<vector<int>>> tab(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int k = 1; k <= 2; k++)
                {
                    int profit = 0;
                    if(j) {
                        profit = max(tab[i+1][0][k]-prices[i], tab[i+1][1][k]);
                    }
                    else    {
                        profit = max(tab[i+1][1][k-1]+prices[i], tab[i+1][0][k]);
                    }
                    tab[i][j][k] = profit;
                }
            }
        }
        return tab[0][1][2];
    }
};