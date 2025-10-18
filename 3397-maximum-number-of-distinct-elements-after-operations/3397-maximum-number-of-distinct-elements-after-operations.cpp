class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int prev = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int m = max(nums[i]-k, prev+1);
            if(m <= nums[i]+k) {
                ans++;
                prev = m;
            }
        }
        return ans;
    }
};