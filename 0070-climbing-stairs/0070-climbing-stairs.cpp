class Solution {
    int solve(int n, vector<int>& dp) {
        if(n == 0) {
            return 1;
        }
        else if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int oneStep = solve(n-1, dp);
        int twoStep = solve(n-2, dp);
        return dp[n] = oneStep + twoStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int steps =  solve(n, dp);
        return steps;
        // if(n<=1) {
        //     return 1;
        // }
        // int prev = 1;
        // int prev2 = 1;
        // int cur;
        // for(int i = 2; i <= n; i++)
        // {
        //     cur = prev + prev2;
        //     prev2 = prev;
        //     prev = cur;
        // }
        // return cur;
    }
};