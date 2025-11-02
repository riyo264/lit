class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i > -1; i--) 
        {
            if(k == 1) {
                return nums[i];
            }
            k--;
        }
        return 0;
    }
};