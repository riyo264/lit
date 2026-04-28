class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        for(auto x : freq) {
            ans += x.second*(x.second-1)/2;
        }
        return ans;
    }
};