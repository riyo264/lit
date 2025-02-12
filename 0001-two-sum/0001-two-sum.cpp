class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int a = -1;
        int b = -1;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i]+nums[j]!=target)
                {
                    continue;
                }
                else if(nums[i]+nums[j]==target)
                {
                   a = i;
                   b = j;
                   break; 
                }
            }
            if((a!=-1) && (b!=-1))
            {
                break;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};