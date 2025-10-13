class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long prod = 1;
        bool zero = false;
        bool tzero = false;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0) {
                prod = prod * nums[i];   
            }
            else {
                cnt++;
                if(cnt >= 2) {
                    tzero = true;
                }
                zero = true;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(tzero) {
                nums[i] = 0;
            }
            else if(nums[i] == 0){
                nums[i] = (int)prod;
            }
            else{
                if(zero) {
                    nums[i] = 0;
                }
                else {
                    nums[i] = (int)prod / nums[i];
                }
            }
        }
        return nums;
    }
};