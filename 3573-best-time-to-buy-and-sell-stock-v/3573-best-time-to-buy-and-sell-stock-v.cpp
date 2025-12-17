class Solution {
public:
    // long long solve(int i, int status, int rem, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
    //     int n = prices.size();
    //     if (rem == 0) return 0;
    //     if (i == n) {
    //         if (status == 0) return 0;
    //         else return LLONG_MIN / 4;
    //     }
    //     if (dp[i][status][rem] != LLONG_MIN) return dp[i][status][rem];
    //     long long best = solve(i+1, status, rem, prices, dp);
    //     if (status == 0) {
    //         best = max(best, -prices[i] + solve(i+1, 1, rem, prices, dp));
    //         best = max(best,  prices[i] + solve(i+1, 2, rem, prices, dp));
    //     }
    //     else if (status == 1) {
    //         best = max(best, prices[i] + solve(i+1, 0, rem-1, prices, dp));
    //     }
    //     else {
    //         best = max(best, -prices[i] + solve(i+1, 0, rem-1, prices, dp));
    //     }
    //     return dp[i][status][rem] = best;
    // }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(k+1, LLONG_MIN)));
        // return solve(0, 0, k, prices, dp);

        const long long NEG_INF = -4e18;
        vector<vector<vector<long long>>> tab(n+1, vector<vector<long long>>(3, vector<long long>(k+1, NEG_INF)));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                tab[i][j][0] = 0;
            }
        }
        for(int rem = 0; rem < k+1; rem++)
        {
            tab[n][0][rem] = 0;
        }
        for(int i = n-1; i >= 0; i--)
        {
            for(int status = 0; status <= 2; status++)
            {
                for(int rem = 1; rem <= k; rem++)
                {
                    long long best = tab[i+1][status][rem];
                    if (status == 0) {
                        best = max(best, -prices[i] + tab[i+1][1][rem]);
                        best = max(best,  prices[i] + tab[i+1][2][rem]);
                    }
                    else if (status == 1) {
                        best = max(best, prices[i] + tab[i+1][0][rem-1]);
                    }
                    else {
                        best = max(best, -prices[i] + tab[i+1][0][rem-1]);
                    }
                    tab[i][status][rem] = best;
                }
            }
        }
        return tab[0][0][k];
    }
};
