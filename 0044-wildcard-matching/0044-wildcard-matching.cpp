class Solution {
public:
    int solve(string p, string s, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) {
            return true;
        }
        else if(i == 0 && j > 0) {
            return false;
        }
        else if(j == 0 && i > 0) {
            for(int k = 1; k <= i; k++) {
                if(p[k-1] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(p[i-1] == s[j-1] || p[i-1] == '?') {
            return dp[i][j] = solve(p, s, i-1, j-1, dp);
        }
        if(p[i-1] == '*') {
            return dp[i][j] = (solve(p, s, i-1, j, dp) | solve(p, s, i, j-1, dp));
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(p, s, n, m, dp);

        vector<vector<int>> tab(n+1, vector<int>(m+1, 0));
        tab[0][0] = 1;
        bool flag = true;
        for(int i = 1; i <= m; i++)
        {
            tab[0][i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            if(p[i] != '*') {
                flag = false;
            }
        }
        if(flag == true) {
            for(int i = 1; i <= n; i++) {
                tab[i][0] = 1;
            }
        }
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[j-1] == p[i-1] || p[i-1] == '?') {
                    tab[i][j] = tab[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    tab[i][j] = (tab[i-1][j] | tab[i][j-1]);
                }
                else {
                    tab[i][j] = 0;
                }
            }
        }
        return tab[n][m];
    }
};