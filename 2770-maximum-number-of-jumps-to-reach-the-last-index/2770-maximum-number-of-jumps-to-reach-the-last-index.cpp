class Solution {
public:
    // int solve(int i, int j, vector<int>& nums, int target, vector<vector<int>>& dp) {
    //     if(i == nums.size()-1) {
    //         return 0;
    //     }
    //     if(j > nums.size()-1) {
    //         return INT_MIN;
    //     }
    //     if(dp[i][j] != INT_MIN) {
    //         return dp[i][j]; 
    //     }
    //     int r = nums[j] - nums[i];
    //     int pick = INT_MIN, notpick = INT_MIN;
    //     if(r >= -target && r <= target) {
    //         int take = solve(j, j+1, nums, target, dp);
    //         if(take != INT_MIN) {
    //             pick = 1 + take;
    //         }
    //     }
    //     notpick = solve(i, j+1, nums, target, dp);
    //     return dp[i][j] = max(pick, notpick);
    // }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));
        // int ans = solve(0, 1, nums, target, dp);
        // if(ans != INT_MIN) {
        //     return ans;
        // }
        // return -1;
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = 0;
        }
        for(int i = n-2; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int r = nums[j] - nums[i];
                int pick = INT_MIN, notpick = INT_MIN;
                if(r >= -target && r <= target) {
                    if(j == n-1) {
                        pick = 1;
                    }
                    int take = dp[j][j+1];
                    if(take != INT_MIN) {
                        pick = 1 + take;
                    }
                }
                notpick = dp[i][j+1];
                dp[i][j] = max(pick, notpick);
            }
        }
        int ans = dp[0][1];
        return (ans == INT_MIN) ? -1 : ans;

    }
};