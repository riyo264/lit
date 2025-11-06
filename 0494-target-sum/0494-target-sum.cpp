class Solution {
    int solve(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(target+1, 0), cur(target+1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int sum = 0; sum <= target; sum++) 
            {
                int notTake = prev[sum];
                int take = 0;
                if(nums[i] <= sum) take = prev[sum - nums[i]];
                cur[sum] = (notTake + take);
            }
            prev = cur;
        }
        return prev[target];
    }
    int count(int n, int d, vector<int>& arr) {
        int totalsum = 0;
        for(auto &it : arr) totalsum += it;
        if(totalsum - d < 0 || (totalsum - d) % 2) return false;
        return solve(arr, (totalsum - d) / 2); 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return count(n, target, nums);
    }
};