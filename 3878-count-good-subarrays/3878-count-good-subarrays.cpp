class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<tuple<int,int,int>> prev; 
        for(int i = 0; i < n; i++) {
            vector<tuple<int,int,int>> curr;

            curr.push_back({nums[i], nums[i], 1});

            for(auto &[o, m, cnt] : prev) {
                int new_or = o | nums[i];
                int new_max = max(m, nums[i]);

                if(!curr.empty() && 
                   get<0>(curr.back()) == new_or &&
                   get<1>(curr.back()) == new_max) {
                    get<2>(curr.back()) += cnt;
                } else {
                    curr.push_back({new_or, new_max, cnt});
                }
            }

            for(auto &[o, m, cnt] : curr) {
                if(o == m) ans += cnt;
            }

            prev = curr;
        }

        return ans;
    }
};