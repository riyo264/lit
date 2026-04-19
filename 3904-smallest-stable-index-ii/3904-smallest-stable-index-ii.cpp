class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);
        int maxum = INT_MIN, minum = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            maxum = max(maxum, nums[i]);
            maxi[i] = maxum;
        }
        for(int i = n-1; i > -1; i--) 
        {
            minum = min(minum, nums[i]);
            mini[i] = minum;
        }
        for(int i = 0; i < n; i++) {
            if(maxi[i]-mini[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};