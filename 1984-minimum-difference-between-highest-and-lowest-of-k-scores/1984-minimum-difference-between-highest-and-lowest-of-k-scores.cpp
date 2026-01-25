class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = k-1;
        int ans = INT_MAX;
        while(r < n) 
        {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int i = l; i <= r; i++)
            {
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);
            }
            ans = min(ans, (maxi - mini));
            l++;
            r++;
        }
        return ans;
    }
};