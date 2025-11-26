class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            int s = 0;
            for(auto x : mpp) {
                if(x.first < nums[i]) {
                    s += x.second;
                }
            }
            ans[i] = s;
        }
        return ans;
    }
};