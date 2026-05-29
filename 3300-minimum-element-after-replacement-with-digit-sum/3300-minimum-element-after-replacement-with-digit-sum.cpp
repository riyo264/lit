class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            int sum = 0;
            while(x >= 1) {
                sum += (x%10);
                x /= 10;
            }
            ans = min(sum, ans);
        }
        return ans;
    }
};