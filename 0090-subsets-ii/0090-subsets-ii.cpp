class Solution {
    void subset2(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for(int idx = i; idx < nums.size(); idx++)
        {
            if(idx!=i && nums[idx] == nums[idx-1]) continue;
            temp.push_back(nums[idx]);
            subset2(idx+1, nums, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subset2(0, nums, temp, ans);
        return ans;
    }
};