class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) 
        {
            mpp[nums[i]]++;
        }
        for(auto x : mpp) 
        {
            if(x.second == 2) {
                ans.push_back(x.first);
                break;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(mpp[i] == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};