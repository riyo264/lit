class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 0;
        int l = 0;
        int r = 0;
        int total = nums[l];
        while(r < nums.size()) 
        {
            if(total < target) {
                r++;
                if(r < nums.size()){
                    total = total + nums[r];
                }
            }
            else if(total >= target) {
                if(len == 0) {
                    len = r - l + 1;
                }
                else {
                    len = min(len, (r-l+1));
                }
                total = total - nums[l];
                l++;
            }
        }
        return len;
    }
};