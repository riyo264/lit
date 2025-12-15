class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = INT_MAX;
        for(int i = n-1; i > -1; i--)
        {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int x = stoi(s);
            if (mpp.count(x)) {
                ans = min(ans, mpp[x]-i);
            }
            mpp[nums[i]] = i;
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};