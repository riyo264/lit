class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sufsum(n, 0);
        vector<int> ans(n, 0);
        for(int i = n-2; i >= 0; i--) {
            sufsum[i] = sufsum[i+1] + nums[i+1];
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            ans[i] = abs(sum - sufsum[i]);
            sum += nums[i];
        }
        return ans;
    }
};