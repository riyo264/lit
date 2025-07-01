class Solution {
private:
    int helper(vector<int>& nums, vector<int>& dp, int n) {
        dp[0] = nums[0];
        for(int i = 1; i <= n; i++) 
        {
            int pick = nums[i];
            if(i > 1) {
                pick += dp[i-2];
            }
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        return helper(nums, dp, n-1);
    }
};