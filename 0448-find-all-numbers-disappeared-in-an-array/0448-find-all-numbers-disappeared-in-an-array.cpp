class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN;
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            // maxn = max(maxn, nums[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(mpp.count(i) == 0) {
                ans.push_back(i);
            }
        }
        // if(ans.size() == 0) {
        //     for(int i = maxn+1; i <= n; i++)
        //     {
        //         ans.push_back(i);
        //     }
        // }
        return ans;
    }
};