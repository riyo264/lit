class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int lastIndex = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int j = 0; j <= i-1; j++)
            {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], 1+dp[j]);
                    if(dp[i] == 1+dp[j]) {
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(lastIndex != hash[lastIndex]) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};