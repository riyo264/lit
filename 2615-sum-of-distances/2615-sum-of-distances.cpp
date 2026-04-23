class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        for(auto& it : mpp) 
        {
            vector<int> id = it.second;
            long long s = 0;
            for(int x : id) {
                s += x;
            }
            long long ls = 0;
            for(int i = 0; i < id.size(); i++) {
                long long rs = s - ls - id[i];
                long long l = 1LL * id[i] * i - ls;
                long long r = rs - 1LL * id[i] * (id.size()-1-i);
                arr[id[i]] = l+r;
                ls += id[i];
            }
        }
        return arr;
    }
};