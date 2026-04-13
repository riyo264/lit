class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start;
        int j = start;
        while(i >= 0 && j < nums.size())
        {
            if(nums[i] == target && nums[j] != target) {
                return abs(i - start);
            }
            else if(nums[i] != target && nums[j] == target) {
                return abs(j - start);
            }
            else if(nums[i] == target && nums[j] == target) {
                return abs(i - start);
            }
            if(i == 0 && j == nums.size()-1) {
                break;
            }
            if(i > 0) {
                i--;
            }
            if(j < nums.size()-1) {
                j++;
            }
        }
        return -1;
    }
};