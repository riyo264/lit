class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) 
        {
            int j = 1;
            bool flag = false;
            while(j < nums[i]) {
                if((j | (j+1)) == nums[i]) {
                    ans.push_back(j);
                    flag = true;
                    break;
                }
                j++;
            }
            if(flag == false) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};