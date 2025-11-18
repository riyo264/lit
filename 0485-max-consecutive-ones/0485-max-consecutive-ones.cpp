class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) {
                maxi = max(maxi, cnt);
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};