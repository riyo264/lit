class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int sum = nums[0];
        int maxcheck = nums[0];
        while(j < nums.size())
        {
            sum = sum + nums[j];
            if(nums[j] > sum) {
                sum = nums[j];
                i = j;
            }
            maxcheck = max(maxcheck, sum);
            j++;
        }
        if(nums.size() == 1) {
            return sum;
        }
        return maxcheck;
    }
};