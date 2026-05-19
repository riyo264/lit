class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 1) {
                return 1;
            }
            if(nums.size() == 2 && nums[0] == nums[1]) {
                return 1;
            }
            return 2;
        }
        int prevdiff = nums[1] - nums[0];
        int ans = (prevdiff != 0) ? 2 : 1;
        int i = 1;
        while(i+1 < nums.size()) {
            int curdiff = nums[i+1] - nums[i];
            if(curdiff > 0 && prevdiff <= 0 || curdiff < 0 && prevdiff >= 0) {
                ans++;
                prevdiff = curdiff;
            }
            i++;
        }
        return ans;
    }
};