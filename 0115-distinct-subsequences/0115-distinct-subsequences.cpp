class Solution {
public:
    int solve(string s, string t, vector<vector<int>>& dp, int i, int j) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            return dp[i][j] = solve(s, t, dp, i-1, j-1) + solve(s, t, dp, i-1, j);
        }
        return dp[i][j] = solve(s, t, dp, i-1, j);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = solve(s, t, dp, n-1, m-1);
        return ans;
    }
};