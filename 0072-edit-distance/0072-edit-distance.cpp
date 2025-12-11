class Solution {
public:
    int solve(string s, string t, vector<vector<int>>& dp, int i, int j) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            return dp[i][j] = 0 + solve(s, t, dp, i-1, j-1);
        }
        return dp[i][j] = 1 + min(solve(s, t, dp, i-1, j), min(solve(s, t, dp, i, j-1), solve(s, t, dp, i-1, j-1)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // int ans = solve(word1, word2, dp, n-1, m-1);
        // return ans;
        vector<vector<int>> tab(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++)
        {
            tab[i][0] = i;
        }
        for(int j = 0; j <= m; j++)
        {
            tab[0][j] = j;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(word1[i-1] == word2[j-1]) {
                    tab[i][j] = 0 + tab[i-1][j-1];
                }
                else {
                    tab[i][j] = 1 + min(tab[i-1][j], min(tab[i][j-1], tab[i-1][j-1]));
                }
            }
        }
        return tab[n][m];
    }
};