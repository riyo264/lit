class Solution {
public:
    void findComb(int i, int target, vector<int>& nums, vector<vector<int> >& ans, vector<int>& ds) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]){
                continue;
            }
            if(nums[j] > target){
                break;
            }
            ds.push_back(nums[j]);
            findComb(j+1, target-nums[j], nums, ans, ds);
            ds.pop_back();
        }  
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};