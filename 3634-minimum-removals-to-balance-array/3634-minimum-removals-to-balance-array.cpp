class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int i = 0; 
        int j = 0;
        int len = 0;
        while(j < n && i <= j) {
            long long target = (long long)(nums[i]) * k;
            while(j < n && nums[j] <= target) {
                len = max(len, (j-i+1));
                j++;
            }
            while(j < n && nums[j] > target) {
                i++;
                target = (long long)(nums[i]) * k;
            }
        }
        return (n - len);
    }
};