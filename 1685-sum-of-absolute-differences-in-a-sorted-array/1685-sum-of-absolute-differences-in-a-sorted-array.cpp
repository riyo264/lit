class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(); 
        int sum = 0;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int ls = 0;
        for(int i = 0; i < n; i++) {
            int rs = sum - ls - nums[i];
            int l = abs(ls - (nums[i] * i));
            int r = abs(rs - (nums[i] * (n-1-i)));
            res[i] = l+r;
            ls += nums[i];
        }
        return res;
    }
};