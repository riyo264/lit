class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int suf = 1;
        int pref = 1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(suf == 0)
            {
                suf = 1;
            }
            if(pref == 0)
            {
                pref = 1;
            }
            suf = suf * nums[i];
            pref = pref * nums[n-i-1];
            ans = max(ans, max(suf, pref));
        }
        return ans;
    }
};