class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long cnt = 0;
        unordered_map<int, int> suff;
        unordered_map<int, int> pref;
        for(int i = 0; i < n; i++)
        {
            suff[nums[i]]++;
        }
        for(int j = 0; j < n; j++)
        {
            suff[nums[j]]--;
            cnt += (long long)pref[2 * nums[j]] * suff[2 * nums[j]];
            pref[nums[j]]++; 
        }
        return cnt % MOD;
    }
};