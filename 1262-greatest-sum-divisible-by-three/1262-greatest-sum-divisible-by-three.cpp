class Solution {
public:
    long long solve(vector<int>& nums, int i, int rem, vector<vector<long long>>& dp) {
        if (i == nums.size()) {
            return (rem == 0 ? 0LL : LLONG_MIN/4);
        }
        if (dp[i][rem] != LLONG_MIN) return dp[i][rem];
        long long pick = nums[i] + solve(nums, i + 1, (rem + nums[i]) % 3, dp);
        long long skip = solve(nums, i + 1, rem, dp);

        return dp[i][rem] = max(pick, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(3, LLONG_MIN));
        long long ans = solve(nums, 0, 0, dp);
        return (int)ans;
    }
};
