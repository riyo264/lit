class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int check = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n-2; i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(target - sum);
                if(diff < check) {
                    check = diff;
                    ans = sum;
                }
                if(sum == target) return sum;
                else if(sum > target) {
                    r--;
                }
                else if(sum < target) {
                    l++;
                }
            }
        }
        return ans;
    }
};