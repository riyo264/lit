class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int x = sum % p;
        if(x == 0) {
            return 0;
        }
        unordered_map<int, int> mpp;
        long long pref = 0;
        mpp[0] = -1;
        int ans = nums.size();  
        for(int i = 0; i < n; i++)
        {
            pref = (pref + nums[i]) % p;
            int rem = (pref - x + p) % p;

            if(mpp.count(rem)) {
                ans = min(ans, i - mpp[rem]);
            }
            mpp[(int)pref] = i;
        }
        if(ans == nums.size()) {
            return -1;
        }
        return ans;
    }
};