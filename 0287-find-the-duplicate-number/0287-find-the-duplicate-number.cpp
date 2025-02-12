class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            if(nums[i]==nums[i+1])
            {
                ans = nums[i];
                break;
            }
            else{
                continue;
            }
        }
        return ans;
    }
};