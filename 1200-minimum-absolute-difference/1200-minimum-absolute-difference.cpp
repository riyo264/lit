class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        queue<vector<int>> q;
        int abs_diff = INT_MAX;
        for(int i = 0; i < n-1; i++)
        {
            vector<int> pairs;
            if(abs(nums[i+1] - nums[i]) < abs_diff) {
                while(!q.empty()) {
                    q.pop();
                }
                abs_diff = abs(nums[i+1] - nums[i]);
                pairs = {nums[i], nums[i+1]};
                q.push(pairs);
            }
            else if(abs(nums[i] - nums[i+1]) == abs_diff) {
                pairs = {nums[i], nums[i+1]};
                q.push(pairs);
            }
            else {
                continue;
            }
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};