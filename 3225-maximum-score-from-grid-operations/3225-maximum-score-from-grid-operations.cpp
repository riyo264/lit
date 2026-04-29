class Solution {
public:
    long long solve(int prevStatus, int prevlen, int col, vector<vector<long long>>& pref, int n, vector<vector<vector<long long>>>& dp) {
        if(col == n+1) {
            return 0;
        }
        if(dp[prevStatus][prevlen][col] != -1) {
            return dp[prevStatus][prevlen][col];
        }
        long long ans = 0;
        for(int i = 0; i <= n; i++) {
            long long prevsum = 0, cursum = 0;
            if(prevStatus == 0 && col > 1 && i > prevlen) {
                prevsum = pref[i][col-1] - pref[prevlen][col-1];
            }
            if(prevlen > i) {
                cursum = pref[prevlen][col] - pref[i][col];
            }
            long long ans1 = cursum + prevsum + solve(1, i, col+1, pref, n, dp);
            long long ans2 = prevsum + solve(0, i, col+1, pref, n, dp);

            ans = max(ans,max(ans1, ans2));
        }
        return dp[prevStatus][prevlen][col]=ans;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> pref(n+1, vector<long long>(n+1, 0));
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n+1, vector<long long>(n+1, -1)));
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= n; j++) { 
                pref[j][i+1] = pref[j-1][i+1] + grid[j-1][i];
            }
        }
        return solve(0, 0, 1, pref, n, dp);
    }
};