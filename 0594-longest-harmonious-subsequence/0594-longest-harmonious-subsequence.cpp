class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int x : nums) 
        {
            mpp[x]++;
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if(mpp.count(x+1)) {
                ans = max(ans, mpp[x]+mpp[x+1]);
            }
        }
        return ans;
    }
};