class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        if(k == 0) {
            return n;
        }
        int maxi = nums[n-k];
        for(int x : nums) {
            if(x < maxi) ans++;
            else {
                break;
            }
        }
        return ans;
    }
};