class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto x : mpp) {
            vector<int> ind_arr = x.second;
            int len = ind_arr.size();
            if(len >= 3) {
                int l = 0;
                int r = 2;
                while(r < len) {
                    int dis = (abs(ind_arr[l]-ind_arr[l+1]) + abs(ind_arr[l+1]-ind_arr[r]) + abs(ind_arr[l]-ind_arr[r]));
                    ans = min(ans, dis);
                    l++;
                    r++;
                }
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};