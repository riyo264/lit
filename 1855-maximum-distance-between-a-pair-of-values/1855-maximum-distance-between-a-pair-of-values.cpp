class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int dist = 0;
        for(int i = 0; i < n; i++) {
            int x = nums1[i];
            int l = i;
            int r = nums2.size()-1;
            while(l <= r) {
                int m = l + (r-l)/2;
                if(nums2[m] == x) {
                    dist = max(dist, abs(m-i));
                    l = m + 1;
                }
                else if(nums2[m] > x) {
                    dist = max(dist, abs(m-i));
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        return dist;
    }
};