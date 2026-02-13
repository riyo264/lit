class Solution {
public:
    // long long solve(int i, int j, int k, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<long long>>>& dp) {
    //     if(k == 0) return 0;
    //     if(i < 0 || j < 0) {
    //         return LLONG_MIN;
    //     }
    //     if(dp[i][j][k] != -1) return dp[i][j][k];
    //     long long take = solve(i-1, j-1, k-1, nums1, nums2, dp);
    //     if(take != LLONG_MIN) {
    //         take += (long long)nums1[i] * (long long)nums2[j];
    //     }
    //     return dp[i][j][k] = max(solve(i-1, j, k, nums1, nums2, dp), max(solve(i, j-1, k, nums1, nums2, dp), take));
    // }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, LLONG_MIN)));
        for(int i = 0; i <= n; i++) 
        {
            for(int j = 0; j <= m; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 1; j <= m; j++) 
            {
                for(int K = 1; K <= k; K++)
                {
                    dp[i][j][K] = max(dp[i][j][K], dp[i-1][j][K]);
                    dp[i][j][K] = max(dp[i][j][K], dp[i][j-1][K]);
                    if(dp[i-1][j-1][K-1] != LLONG_MIN) {
                        dp[i][j][K] = max(
                            dp[i][j][K],
                            dp[i-1][j-1][K-1] +
                            (long long)nums1[i-1] * nums2[j-1]
                        );
                    }
                }
            }
        }
        return dp[n][m][k];
    }
};