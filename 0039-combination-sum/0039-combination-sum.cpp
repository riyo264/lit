class Solution {
public:
    void Combination(int index, int target, vector<int>& candidates, vector<vector<int> >& ans, vector<int>& nums){
        if(index == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(nums);
            }
            return;
        }
        if(candidates[index] <= target)
        {
            nums.push_back(candidates[index]);
            Combination(index, target - candidates[index], candidates, ans, nums);
            nums.pop_back();
        }
        Combination(index+1, target, candidates, ans, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> nums;
        Combination(0, target, candidates, ans, nums);
        return ans;
    }
};