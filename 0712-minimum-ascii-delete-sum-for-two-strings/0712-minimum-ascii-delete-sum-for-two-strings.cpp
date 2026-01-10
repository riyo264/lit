class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) {
            return dp[i][j] = int(s1[i-1]) + solve(i-1, j-1, s1, s2, dp);
        }
        return dp[i][j] = max(solve(i, j-1, s1, s2, dp), solve(i-1, j, s1, s2, dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<char> common;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int commonSum = solve(n, m, s1, s2, dp);
        int total = 0;
        for (char c : s1) total += int(c);
        for (char c : s2) total += int(c);
        return total - 2 * commonSum;
    }
};