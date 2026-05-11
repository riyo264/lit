class Solution {
public:
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        int n = s3.size();
        int m = s1.size();
        int p = s2.size();
        if(i == n) {
            return true;
        }
        if(dp[j][k] != -1) {
            return dp[j][k];
        }
            bool f1 = false;
            bool f2 = false;
            char c = s3[i];
            if(s1[j] == c) {
                f1 = solve(i+1, j+1, k, s1, s2, s3, dp);
            }
            if(s2[k] == c) {
                f2 = solve(i+1, j, k+1, s1, s2, s3, dp);
            }
        return dp[j][k] = (f1 || f2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s3.size();
        int m = s1.size();
        int p = s2.size();
        if(m+p != n) {
            return false;
        }
        vector<vector<int>> dp(m+1, vector<int>(p+1, -1));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};