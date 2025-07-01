class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1]) {
                if(nums[0] < nums[nums.size()-1]) {
                    return false;
                }
                for(int j = i+1; j < nums.size(); j++) 
                {
                    if(nums[j] < nums[j-1]) {
                        return false;
                    }
                    else if(j == nums.size()-1) {
                        return true;
                    }
                }
            }
        }
        return true;
    }
};