class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int t_sum = 0;
        int d_sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) 
        {
            t_sum += nums[i];
            while(nums[i] > 0) {
                int x = nums[i] % 10;
                d_sum += x;
                nums[i] /= 10;
            }
        }
        return abs(t_sum - d_sum);
    }
};