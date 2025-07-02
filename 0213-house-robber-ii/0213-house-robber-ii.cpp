class Solution {
    int helper(vector<int>& arr, vector<int>& dp, int n) {
        dp[0] = arr[0];
        for(int i = 1; i <= n; i++)
        {
            int pick = arr[i];
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
        vector<int> dp1(n-1, 0);
        vector<int> dp2(n-1, 0);
        vector<int> temp1;
        vector<int> temp2;
        if(n == 1) {
            return nums[0];
        }
        for(int i = 0; i < n; i++) 
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1, dp1, n-2), helper(temp2, dp2, n-2));
    }
};