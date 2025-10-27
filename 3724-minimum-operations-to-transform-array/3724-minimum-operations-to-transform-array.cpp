class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        long long app = nums2[n];
        long long tilln = 0;
        long long ext = LLONG_MAX;
        for(int i = 0 ; i < n; i++)
        {
            tilln += abs(nums1[i] - nums2[i]);
            if(app <= max(nums1[i], nums2[i]) && app >= min(nums1[i], nums2[i])) {
                ext = 0;
            }
            ext = min(ext, min(abs(app - nums1[i]), abs(app - nums2[i])));
        }
        return tilln+ext+1LL;
    }
};