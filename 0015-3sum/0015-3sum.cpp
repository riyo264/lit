class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());
        for(int j = 0; j < nums.size()-2; j++)
        {
            if (j > 0 && nums[j] == nums[j - 1]) continue;
            int l = j+1;
            int r = nums.size()-1;
            while(l < r)
            {
                if(nums[l]+nums[r]+nums[j] == 0) {
                    result.push_back({nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if(nums[j]+nums[l]+nums[r] > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return result;
    }
};