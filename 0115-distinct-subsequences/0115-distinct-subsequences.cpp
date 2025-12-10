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
        vector<vector<int>> dp(n, vector<int>(m, -1)); // For the Memoization
        vector<vector<double>> tab(n+1, vector<double>(m+1, 0)); // For the Tabulation
        for(int i = 0; i <= n; i++)
        {
            tab[i][0] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1]) {
                    tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
                }
                else {
                    tab[i][j] = tab[i-1][j];
                }
            }
        }
        return (int)tab[n][m];
        // int ans = solve(s, t, dp, n-1, m-1);
        // return ans;
    }
};