class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int cnt = 0;
        if(nums[0] > nums[1]) {
            return false;
        }
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i-1]) {
                if(!flag) {
                    flag = true;
                    cnt++;
                }
            }
            else if(nums[i] < nums[i-1]) {
                if(flag) {
                    flag = false;
                    cnt++;
                }
            }
            else {
                return false;
            }
        }
        if(cnt == 2) {
            return true;
        }
        return false;
    }
};