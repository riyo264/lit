class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int j = n-1;
        int sum_F = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum_F += i*nums[i];
            sum += nums[i];
        }
        for(int i = 0; i < n; i++) {
            if(i > 0) {
                sum_F -= ((n-1)*nums[j]);
                sum_F += (sum - nums[j]);
                j--;
            }
            ans = max(ans, sum_F);
        }
        return ans;
    }
};