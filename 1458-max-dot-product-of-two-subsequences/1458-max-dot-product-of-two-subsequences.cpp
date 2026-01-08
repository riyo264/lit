class Solution {
public:
    int solve(int i, int j, int n, int m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i >= n || j >= m) {
            return INT_MIN;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int pick = nums1[i]*nums2[j] + max(0,solve(i+1, j+1, n, m, nums1, nums2, dp));
        int skip1 = solve(i+1, j, n, m, nums1, nums2,dp);
        int skip2 = solve(i, j+1, n, m, nums1, nums2, dp);
        return dp[i][j] = max(pick, max(skip1, skip2));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MIN));
        // return solve(0, 0, n, m, nums1, nums2, dp);
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int pick = nums1[i]*nums2[j] + max(0,dp[i+1][j+1]);
                int skip1 = dp[i+1][j];
                int skip2 = dp[i][j+1];
                dp[i][j] = max(pick, max(skip1, skip2));
            }
        }
        return dp[0][0];
    }
};