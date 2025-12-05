class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int pref = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            pref += nums[i];
            if(abs(sum - (2*pref)) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};