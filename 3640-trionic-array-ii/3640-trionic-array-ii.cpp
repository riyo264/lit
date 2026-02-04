class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = -1e18;
        long long a = -1e17;
        long long b = -1e17;
        long long c = -1e17;
        long long prev = nums[0];
        for(int i = 1; i < n; i++) 
        {
            long long cur = nums[i];
            long long na = -1e17;
            long long nb = -1e17;
            long long nc = -1e17;
            if(cur > prev) {
                na = max(prev, a) + cur;
                nc = max(b, c) + cur;
            }
            else if(cur < prev) {
                nb = max(a, b) + cur;
            }
            a = na;
            b = nb;
            c = nc;
            ans = max(ans, c);
            prev = cur;
        }
        return ans;
    }
};