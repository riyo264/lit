class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i < m || j < n) 
        {
            if(i >= m) {
                ans.push_back(nums2[j]);
                j++;
                continue;
            }
            if(j >= n) {
                ans.push_back(nums1[i]);
                i++;
                continue;
            }
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = ans;
    }
};