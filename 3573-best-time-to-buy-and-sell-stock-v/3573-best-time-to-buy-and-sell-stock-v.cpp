class Solution {
public:
    long long solve(int i, int status, int rem, vector<int>& prices,
                    vector<vector<vector<long long>>>& dp) {

        int n = prices.size();

        if (rem == 0) return 0;
        if (i == n) {
            if (status == 0) return 0;
            else return LLONG_MIN / 4;
        }

        if (dp[i][status][rem] != LLONG_MIN) return dp[i][status][rem];

        long long best = solve(i+1, status, rem, prices, dp);

        if (status == 0) {
            best = max(best, -prices[i] + solve(i+1, 1, rem, prices, dp));
            best = max(best,  prices[i] + solve(i+1, 2, rem, prices, dp));
        }
        else if (status == 1) {
            best = max(best, prices[i] + solve(i+1, 0, rem-1, prices, dp));
        }
        else {
            best = max(best, -prices[i] + solve(i+1, 0, rem-1, prices, dp));
        }

        return dp[i][status][rem] = best;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(3, vector<long long>(k+1, LLONG_MIN))
        );
        return solve(0, 0, k, prices, dp);
    }
};
