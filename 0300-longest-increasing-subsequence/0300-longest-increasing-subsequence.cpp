class Solution {
public:
    // int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
    //     int n = nums.size();
    //     if(i == n) {
    //         return 0;
    //     }
    //     if(dp[i][prev+1] != -1) {
    //         return dp[i][prev+1];
    //     }
    //     int notTake = solve(i+1, prev, nums, dp);
    //     int take = 0;
    //     if(prev == -1 || nums[i] > nums[prev]) {
    //         take = 1 + solve(i+1, i, nums, dp);
    //     }
    //     return dp[i][prev+1] = max(take, notTake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(0, -1, nums, dp);

        // vector<vector<int>> tab(n+1, vector<int>(n+1, 0));
        // vector<int> cur(n+1, 0), after(n+1, 0);
        // for(int i = n-1; i >= 0; i--)
        // {
        //     for(int prev = i-1; prev >= -1; prev--)
        //     {
        //         int notTake = after[prev+1];
        //         int take = 0;
        //         if(prev == -1 || nums[i] > nums[prev]) {
        //             take = 1 + after[i+1];
        //         }
        //         cur[prev+1] = max(take, notTake);   
        //     }
        //     after = cur;
        // }
        // return after[0];


        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};