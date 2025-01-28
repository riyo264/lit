class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (1<<nums.size());
        vector<vector<int> > ans;
        for(int i=0; i<n; i++)
        {
            vector<int> list;
            for(int j=0; j<nums.size(); j++)
            {
                if(((i)&(1<<j))>0)
                {
                    list.push_back(nums[j]);
                }
                else
                {
                    continue;
                }
            }
            ans.push_back(list);
        }
        return ans;
    }

};