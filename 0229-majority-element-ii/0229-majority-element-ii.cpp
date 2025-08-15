class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major = n/3;
        unordered_map<int, int> mpp;
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it : mpp)
        {
            if(it.second > major) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};