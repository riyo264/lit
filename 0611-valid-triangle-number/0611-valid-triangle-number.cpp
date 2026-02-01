class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int r = n-1;
        int ans = 0;
        while(r > 1) {
            for(int i = 0; i <= r-2; i++)
            {
                for(int j = 1; j <= r-1; j++) 
                {
                    if((i != j) && nums[i] + nums[j] > nums[r]) {
                        ans++;
                    }
                }
            }
            r--;
        }
        return ans;
    }
};