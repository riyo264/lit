class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long ans = 0;
        int mod = 1000000007;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int m = -1;
        vector<long long> pow2(n,1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        while(l <= h) 
        {
            int mid = l + (h-l)/2;
            if(nums[mid] >= target) {
                h = mid - 1;
            }
            else {
                m = mid;
                l = mid+1;
            }
        }
        int L = 0;
        int R = m;
        while(L <= R) 
        {
            if(nums[L]+nums[R] <= target) {
                ans = (ans + pow2[R-L]) % mod;
                L++;
            }
            else {
                R--;
            }
        }
        return ans;
    }
};