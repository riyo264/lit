class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1) {
                ones++;
            }
        }
        int l = 0;
        int r = ones-1;
        int o = 0;
        for(int i = l; i <= r; i++)
        {
            if(nums[i] == 1) {
                o++;
            }
        }
        int max_ones = o;
        while(r < 2*n-1) {
            max_ones = max(o, max_ones);
            if(nums[l%n] == 1) {
                o--;
            }
            if(nums[(r+1)%n] == 1) {
                o++;
            }
            l++;
            r++;
        }
        return (ones - max_ones);
    }
};