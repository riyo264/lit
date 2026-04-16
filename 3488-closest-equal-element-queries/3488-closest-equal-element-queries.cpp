class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int q : queries) {
            auto &vec = mpp[nums[q]];
            if(vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(vec.begin(), vec.end(), q);
            int pos = it - vec.begin();
            int d = INT_MAX;
            int next = vec[(pos + 1) % vec.size()];
            d = min(d, min(abs(next - q), n - abs(next - q)));
            int prev = vec[(pos - 1 + vec.size()) % vec.size()];
            d = min(d, min(abs(prev - q), n - abs(prev - q)));
            ans.push_back(d);
        }
        return ans;
    }
};