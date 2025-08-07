class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        int i = 0;
        int j = 0;
        bool flag = true;
        while(i < nums.size() && j < nums.size())
        {
            if(flag == true) {
                if(nums[i] > 0) {
                    result.push_back(nums[i]);
                    flag = false;
                    if(i < nums.size()-1) {
                        i++;
                    }
                }
                else {
                    i++;
                }
            }
            else {
                if(nums[j] < 0) {
                    result.push_back(nums[j]);
                    flag = true;
                    if(j < nums.size()-1) {
                        j++;
                    }
                }
                else {
                    j++;
                }
            }
            if(result.size() == nums.size()) {
                break;
            }
        }
        return result;
    }
};