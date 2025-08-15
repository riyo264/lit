class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return;
        }
        int check = 0;
        for(int i = n-1; i > -1; i--)
        {
            if(i == 0) {
                check = -1;
            }
            else if(i!=0 && (nums[i] > nums[i-1])) {
                check = i-1;
                break;
            }
        }
        if(check == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            int temp = INT_MAX;
            int idx = -1;
            for(int i = check+1; i < n; i++)
            {
                if(nums[i] > nums[check]) {
                    temp = min(temp, nums[i]);
                    if(temp == nums[i]) {
                        idx = i;
                    }
                }
            }
            nums[check] = nums[check] ^ nums[idx];
            nums[idx] = nums[check] ^ nums[idx];
            nums[check] = nums[check] ^ nums[idx];
            sort(nums.begin()+check+1, nums.end());
        }
        return;
    }
};