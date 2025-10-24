class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, sum1 = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        sum1 = sum/2;
        vector<bool> prev(sum1 + 1, false), cur(sum1 + 1, false);
        if(sum % 2 != 0) return false;
        else {
            prev[0] = cur[0] = true;
            if(nums[0] <= sum1) {
                prev[nums[0]] = true;
            }
            for(int i = 1; i < n; i++)
            {
                for(int target = 1; target <= sum1; target++)
                {
                    bool notTake = prev[target];
                    bool take = false;
                    if(nums[i] <= target) {
                        take = prev[target - nums[i]];
                    }
                    cur[target] = notTake || take;
                }
                prev = cur;
            }
        }
        if(prev[sum1] == true) {
            return true;
        }
        return false;
    }
};