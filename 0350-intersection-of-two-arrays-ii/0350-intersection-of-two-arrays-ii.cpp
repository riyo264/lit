class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            mpp[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(mpp[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                mpp[nums2[i]]--;
            }
        }
        return ans;
    }
};