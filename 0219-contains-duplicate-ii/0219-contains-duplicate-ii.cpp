class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mpp[nums[i]] != 0) {
                if(abs(i+1 - mpp[nums[i]]) <= k) {
                    return true;
                }
            }
            mpp[nums[i]] = i+1;
        }
        return false;
    }
};