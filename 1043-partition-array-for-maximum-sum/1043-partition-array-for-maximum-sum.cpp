class Solution {
public:
    // int maxSum(int i, int k, vector<int>& arr, vector<int>& dp) {
    //     int n = arr.size();
    //     if(i == n) {
    //         return 0;
    //     }
    //     if(dp[i] != -1) return dp[i];
    //     int maxi = INT_MIN;
    //     int len = 0;
    //     int maxans = INT_MIN;
    //     for(int j = i; j < min(n, i+k); j++) 
    //     {
    //         len++;
    //         maxi = max(maxi, arr[j]);
    //         int sum = maxi*len + maxSum(j+1, k, arr, dp);
    //         maxans = max(sum, maxans);
    //     }
    //     return dp[i] = maxans;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        // return maxSum(0, k, arr, dp);
        for(int i = n-1; i >= 0; i--) 
        {
            int maxi = INT_MIN;
            int len = 0;
            int maxans = INT_MIN;
            for(int j = i; j < min(n, i+k); j++) 
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = maxi*len + dp[j+1];
                maxans = max(sum, maxans);
            }
            dp[i] = maxans;
        }
        return dp[0];
    }
};