class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long x = 0;
        vector<bool> ans(nums.size(), false);
        for(int i = 0; i < nums.size(); i++)
        {
            if(x == 0 && nums[i] == 1) {
                x = 1;
            }
            else if(nums[i] == 1) {
                x = ((x<<1) + 1)%5;
            }
            else {
                x = (x<<1)%5;
            }
            if(x % 5 == 0) {
                ans[i] = true;
            }
        }
        return ans;
    }
};