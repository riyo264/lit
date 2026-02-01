class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int r = n-1;
        int ans = 0;
        while(r > 1) {
            int i = 0; 
            int j = r-1;
            while(i < j) {
                if(nums[i] + nums[j] > nums[r]) {
                    ans += (j - i);     // keeping the j index fixed and taking all pairs of numbers by increasing i
                    j--;
                }
                else{
                    i++;
                }
            }
            r--;
        }
        return ans;
    }
};