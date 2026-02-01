class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(min1 > min2) {
                min1 = min(min1, nums[i]);
            }
            else if(min2 > min1) {
                min2 = min(min2, nums[i]);
            }
            else {
                min1 = min(min1, nums[i]);
            }
        }
        ans += (min1 + min2);
        return ans;
    }
};