class Solution {
private:
    void subseq(int n, int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp) {
        if(i == n) {
            ans.push_back(temp);
            return;
        } 
        temp.push_back(nums[i]);
        subseq(n, i+1, nums, ans,temp);
        temp.pop_back();
        subseq(n, i+1, nums, ans, temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        subseq(n, i, nums, ans, temp);
        return ans;
        // int n = (1<<nums.size());
        // vector<vector<int> > ans;
        // for(int i=0; i<n; i++)
        // {
        //     vector<int> list;
        //     for(int j=0; j<nums.size(); j++)
        //     {
        //         if(((i)&(1<<j))>0)
        //         {
        //             list.push_back(nums[j]);
        //         }
        //         else
        //         {
        //             continue;
        //         }
        //     }
        //     ans.push_back(list);
        // }
        // return ans;
    }

};