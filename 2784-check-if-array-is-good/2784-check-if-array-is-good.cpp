class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }
        if(n <= maxi || n > maxi+1) {
            return false;
        }
        bool flag = false;
        for(auto x : mpp) {
            if(x.first == maxi && x.second == 2) {
                flag = true;
            } 
            else if(x.second > 1) {
                return false;
            }
        }
        return flag;
    }
};