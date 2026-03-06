class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
        int n = s.size();
        int m = p.size();
        if(i >= n && j >= m) {
            return true;
        }
        if(i < n && j >= m) {
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool firstMatch = (i < n && (s[i] == p[j] || p[j] == '.'));
        if(j + 1 < m && p[j+1] == '*') {
            return dp[i][j] =
                solve(s, p, i, j+2, dp) ||
                (firstMatch && solve(s, p, i+1, j, dp));
        }
        if(firstMatch)
            return dp[i][j] = solve(s, p, i+1, j+1, dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};