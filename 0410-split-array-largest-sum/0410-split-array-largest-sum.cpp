class Solution {
public:
     bool isValid(vector<int>& nums, int k, int m) {
        int cap = 0;
        int cnt = 1;
        for (int x : nums) {
            if (cap + x > m) {
                cnt++;
                cap = x;
            } else {
                cap += x;
            }
        }
        if(cnt <= k) {
            return true;
        }
        else {
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        long long tw = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            tw += nums[i];
        }
        long long l = maxi;
        long long h = tw;
        int ans = h;
        while(l <= h) 
        {
            long long m = l + (h-l)/2;
            if(isValid(nums, k, m)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};