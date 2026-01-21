class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if ((x & 1) == 0) {
                ans[i] = -1;
                continue;
            }
            int j = x;
            for (int b = 0; b < 31; b++) {
                if((x & (1 << b)) == 0) {
                    j = x ^ (1 << (b-1));
                    break;
                }
            }
            ans[i] = j;
        }
        return ans;
    }
};
