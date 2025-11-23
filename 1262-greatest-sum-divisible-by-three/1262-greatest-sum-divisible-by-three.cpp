class Solution {
public:
    long long solve(vector<int>& nums, int i, int sumMod, vector<vector<long long>>& dp) {
        if (i == nums.size()) {
            return (sumMod == 0 ? 0LL : LLONG_MIN/4);
        }
        if (dp[i][sumMod] != LLONG_MIN) return dp[i][sumMod];
        long long pick = nums[i] + solve(nums, i + 1, (sumMod + nums[i]) % 3, dp);
        long long skip = solve(nums, i + 1, sumMod, dp);

        return dp[i][sumMod] = max(pick, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(3, LLONG_MIN));
        long long ans = solve(nums, 0, 0, dp);
        return (int)ans;
    }
};
